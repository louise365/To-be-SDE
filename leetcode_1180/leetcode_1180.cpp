// leetcode_1180.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countLetters(string S) {
        if (S.size() < 2)
            return S.size();
        vector<string> vt;
        int sum = 0;
        char pre = S[0];
        int idx = 0;
        for (int i = 1; i < S.size(); i++)
        {
            if (S[i] != pre)
            {
                //sum += i - idx;
                //vt.emplace_back(S.substr(idx,i-idx));
                int n = i - idx;
                sum += (1 + n) * (n) / 2;
                pre = S[i];
                idx = i;
            }
        }
        //if (idx != S.size() - 1)
        {
            //sum += S.size() - idx;
            int n = S.size() - idx;
            sum += (1 + n) * (n) / 2;
            //vt.emplace_back(S.substr(idx, S.size() - idx));
        }
        
        return sum;
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
