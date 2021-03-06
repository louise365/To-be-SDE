// leetcode_422.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        bool ret = true;

        for (int i = 0; i < words.size() && ret; i++)
        {
            int n = words[i].size();
            for (int j = 0; j < n && ret; j++)
            {
                if (j > words.size() || words[i][j] != words[j][i])
                {
                    ret = false;
                    break;
                }
            }
        }

        return ret;
    }
};
int main()
{
    Solution s;
    vector<string> vt = { "abcd","bnrt","crm","dt" };
    s.validWordSquare(vt);
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
