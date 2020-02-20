// leetcode_309.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//comment: if the question has status relationship between before and after, it is proper to use dynamic programing
#include <iostream>
#include <vector>
using namespace std;
//idx = i
//
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for (auto i = 0; i < prices.size(); i++)
        {

        }
        return ret;
    }
};
int main()
{
    Solution s;
    vector<int> vt = { 1,2,3,0,2 };
    cout << s.maxProfit(vt) << endl;
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
