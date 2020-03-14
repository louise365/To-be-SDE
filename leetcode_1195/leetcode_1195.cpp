// leetcode_1195.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <atomic>
#include <thread>

using namespace std;
class FizzBuzz {
private:
    enum class Status {
        NUM, FIZZ, BUZZ, FIZZBUZZ
    };
    int n;
    int idx;
    atomic<Status> s;
    Status getNext(int i)
    {
        ++i;
        if (i % 3 == 0 && i % 15 != 0)
            return Status::FIZZ;
        else if (i % 5 == 0 && i % 15 != 0)
            return Status::BUZZ;
        else if (i % 15 == 0)
            return Status::FIZZBUZZ;
        else
            return Status::NUM;
    }
public:
    FizzBuzz(int n) {
        this->n = n;
        idx = 1;
        s.store(Status::NUM, memory_order_relaxed);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (idx <= n)
        {
            if (Status::FIZZ == s.load(memory_order_relaxed))
            {
                printFizz();
                s.store(getNext(idx++), memory_order_relaxed);
            }
            this_thread::yield();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (idx <= n)
        {
            if (Status::BUZZ == s.load(memory_order_relaxed))
            {
                printBuzz();
                s.store(getNext(idx++), memory_order_relaxed);
            }
            this_thread::yield();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (idx <= n)
        {
            if (Status::FIZZBUZZ == s.load(memory_order_relaxed))
            {
                printFizzBuzz();
                s.store(getNext(idx++), memory_order_relaxed);
            }
            this_thread::yield();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (idx <= n)
        {
            if (Status::NUM == s.load(memory_order_relaxed))
            {
                printNumber(idx);
                s.store(getNext(idx++), memory_order_relaxed);
            }
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
