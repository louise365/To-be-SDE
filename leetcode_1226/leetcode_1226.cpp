// leetcode_1226.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

class DiningPhilosophers {
private:
    enum Status {
        IDLE,BUSY
    };
    atomic<Status> forks[5];
    inline int getIndex(int i)
    {
        if (i >= 0 && i < 5)
            return i;
        else if (i < 0)
            return 4;
        else
            return 0;
    }
public:
    DiningPhilosophers() {
        for (int i = 0;i<5;++i)
            forks[i].store(Status::IDLE, memory_order_relaxed);
    }

    void wantsToEat(int philosopher,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork) {
        while (1){
            if (Status::IDLE == forks[philosopher].load(memory_order_relaxed) && 
                Status::IDLE == forks[getIndex(philosopher + 1)].load(memory_order_relaxed))
            {
                forks[philosopher].store(Status::BUSY, memory_order_relaxed);
                forks[getIndex(philosopher + 1)].store(Status::BUSY, memory_order_relaxed);
                pickLeftFork();
                pickRightFork();
                eat();
                putLeftFork();
                forks[philosopher].store(Status::IDLE, memory_order_relaxed);
                putRightFork();
                forks[getIndex(philosopher + 1)].store(Status::IDLE, memory_order_relaxed);
                break;
            }
            else
                this_thread::yield();
        }
    }
};
int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

