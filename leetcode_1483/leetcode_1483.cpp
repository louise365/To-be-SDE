// leetcode_1483.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> rt;
        if (matrix.size() == 0)
            return rt;
        int r = matrix[0].size()-1;
        int b = matrix.size()-1;
        int t = 0, l = 0;
        int count = (r + 1) * (b + 1);
        while (count)
        {
            for (int i = l; i <= r && count; i++, count--)
                rt.push_back(matrix[t][i]);
            t++;
            for (int i = t; i <= b && count; i++, count--)
                rt.push_back(matrix[i][r]);
            r--;
            for (int i = r; i >= l && count; i--, count--)
                rt.push_back(matrix[b][i]);
            b--;
            for (int i = b; i >= t && count; i--, count--)
                rt.push_back(matrix[i][l]);
            l++;
        }
        return rt;
    }
};
int main()
{
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
