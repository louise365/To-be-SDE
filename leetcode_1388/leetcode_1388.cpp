// leetcode_1388.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class StackOfPlates {
private:
    vector<stack<int>> vt;
    int cap;
public:
    StackOfPlates(int cap) {
        this->cap = cap;
    }

    void push(int val) {
        if (cap == 0)
            return;
        if (vt.empty() || vt.back().size() == cap)
        {
            stack<int> st;
            st.emplace(val);
            vt.emplace_back(st);
        }
        else
            vt.back().emplace(val);
    }

    int pop() {
        if (cap == 0)
            return -1;
        int val = -1;
        if (!vt.empty())
        {
            val = vt.back().top();
            if (vt.back().size() == 1)
                vt.erase(vt.end() - 1);
            else
                vt.back().pop();
        }

        return val;
    }

    int popAt(int index) {
        if (cap == 0 || index >= vt.size() || vt[index].empty())
            return -1;
        else
        {
            int val = vt[index].top();
            if (vt[index].size() == 1)
                vt.erase(vt.begin() + index);
            else
                vt[index].pop();
            return val;
        }
    }
};

int main()
{
    StackOfPlates s(2);
    s.push(1);
    s.push(2);
    s.push(3);
    s.popAt(0);
    s.popAt(0);
    s.popAt(0);
    //s.pop();
    //s.pop();
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
