// leetcode_121.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> st;
        for (auto i = 0; i < prices.size(); i++)
        {
            if (!st.size())
            {
                st.push(i);
                continue;
            }
            while (st.size() && prices[st.top()] > prices[i])
                st.push(i);
        }
        int maxV = INT_MIN;
        for (int i = prices.size() - 1; i >= 0 && st.size(); i--)
        {
            while (st.size() && i <= st.top())
                st.pop();
            while (st.size() && prices[i] - prices[st.top()] > maxV)
                maxV = prices[i] - prices[st.top()];
        }
        return maxV != INT_MIN ? maxV : 0;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxV = 0;
        int idx = 0;
        for (auto i = 0; i < prices.size(); i++)
        {
            if (prices[i] < prices[idx])
                idx = i;
            else
                maxV = max(maxV, prices[i] - prices[idx]);
        }
        return maxV;
    }
};
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
