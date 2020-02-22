// leetcode_624.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minV = arrays[0][0];
        int maxV = arrays[0][arrays[0].size()-1];
        int ret = 0;
        for (int i = 1; i<arrays.size();i++)
        {
            int ret1 = max(abs(minV - arrays[i][arrays[i].size() - 1]), abs(maxV - arrays[i][0]));
            ret = max(ret1, ret);
            minV = min(minV, arrays[i][0]);
            maxV = max(maxV, arrays[i][arrays[i].size() - 1]);
        }
        return ret;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> vt;
    vector<int> v;
    v = { 1 };
    vt.push_back(v);
    vt.push_back(v);
    s.maxDistance(vt);
    std::cout << "Hello World!\n";
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
