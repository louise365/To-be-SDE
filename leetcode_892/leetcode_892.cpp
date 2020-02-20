// leetcode_892.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ret += ((grid[i][j] ? 1 : 0) << 1) + (grid[i][j] << 2);
                if (j != 0)
                    ret -= min(grid[i][j], grid[i][j - 1]) << 1;
                if (i != 0)
                    ret -= min(grid[i][j], grid[i - 1][j]) << 1;
            }
        }
        return ret;
    }
};
int main()
{
    Solution s;

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
