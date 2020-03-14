// leetcode_1279.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
//#include <semaphore.h>
using namespace std;
class TrafficLight {
private:
    //sem_t s_lock;
    bool lock;
    int currentRoad;
public:
    TrafficLight() {
        currentRoad = 1;
       // sem_init(&s_lock,0,0);
        lock = false;
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
       // sem_wait(&s_lock);
        while (lock)
            ;
        lock = true;
        if (currentRoad != roadId)
        {
            currentRoad = roadId;
            turnGreen();
        }
        crossCar();
        lock = false;
      //  sem_post(&s_lock);
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
