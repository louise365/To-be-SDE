// leetcode_1389.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> st[2];
    int idx;
    bool direction;
    void transfer()
    {
        while (!st[idx].empty())
        {
            st[1 - idx].emplace(st[idx].top());
            st[idx].pop();
        }
        idx = 1 - idx;
        direction = !direction;
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {
        idx = 0;
        direction = true;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        if (!direction)
            transfer();
        st[idx].emplace(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = peek();
        st[idx].pop();
        return val;
    }

    /** Get the front element. */
    int peek() {
        if (direction)
            transfer();
        int val = st[idx].top();
        return val;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return st[idx].empty();
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
