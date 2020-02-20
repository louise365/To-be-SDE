// leetcode_716.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
class MaxStack {
private:
    vector<int> st;
    int maxV;
    int idx;
public:
    /** initialize your data structure here. */
    MaxStack() {
        maxV = INT_MIN;
        idx = -1;
    }

    void push(int x) {
        if (x >= maxV)
        {
            maxV = x;
            idx = st.size();
        }
        st.push_back(x);
    }

    int pop() {
        int t = st.back();
        st.erase(st.end()-1);
        if (t == maxV)
        {
            maxV = INT_MIN;
            idx = -1;
            for (int i = 0; i < st.size(); i++)
            {
                if (st[i] >= maxV)
                {
                    maxV = st[i];
                    idx = i;
                }
            }
        }
        return t;
    }

    int top() {
        return st.back();
    }

    int peekMax() {
        return maxV;
    }

    int popMax() {
        int t = maxV;
        st.erase(st.begin() + idx);
        maxV = INT_MIN;
        idx = -1;
        for (int i =0;i<st.size();i++)
        {
            if (st[i] >= maxV)
            {
                maxV = st[i];
                idx = i;
            }
        }
        return t;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
int main()
{
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
