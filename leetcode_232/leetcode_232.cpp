// leetcode_232.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while (st1.size()) {
            st2.emplace(st1.top());
            st1.pop();
        }
        st2.emplace(x);
        while (st2.size()) {
            st1.emplace(st2.top());
            st2.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret = st1.top();
        st1.pop();
        return ret;
    }

    /** Get the front element. */
    int peek() {
        return st1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
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
