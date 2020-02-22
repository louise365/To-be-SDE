// leetcode_1099.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        if (A.size() < 2)
            return -1;
        int minV = INT_MAX;
        int ret = -1;
        sort(A.begin(), A.end());
        if (A[0]> K)
            return ret;
        int idx1 = 0;
        int idx2 = A.size() - 1;
        while (idx1 < idx2)
        {
            if (A[idx1] + A[idx2] < K)
            {
                if (minV > K - (A[idx1] + A[idx2]))
                {
                    minV = K - (A[idx1] + A[idx2]);
                    ret = A[idx1] + A[idx2];
                }
                idx1++;
            }
            else
                idx2--;
        }
        return ret;
    }
};
int main()
{
    Solution s;
    vector<int> vt = { 254,914,110,900,147,441,209,122,571,942,136,350,160,127,178,839,201,386,462,45,735,467,153,415,875,282,204,534,639,994,284,320,865,468,1,838,275,370,295,574,309,268,415,385,786,62,359,78,854,944 };
    s.twoSumLessThanK(vt, 200);
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
