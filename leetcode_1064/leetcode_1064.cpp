// leetcode_1064.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int fixedPoint(vector<int>& A) {
        vector<int>::iterator it = upper_bound(A.begin(), A.end(), -1);
        if (it == A.end())
            return -1;
        int ret = -1;
        for(;it!=A.end();it++)
            if ((it - A.begin()) == *it)
            {
                ret = *it;
                break;
            }
        return ret;
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
