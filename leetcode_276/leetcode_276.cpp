// leetcode_276.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//n = 1,k,2;
//n=2,k*k,4;
//n=3,k*(k-1)*2 + (k-1)*(k-1)*k = 2*1*2+1*1*2 = 6;
//n=4,f(2) * 
//f(n) = f(n-2) * (k-1) + f(n-1) * (k-1)
//f(3) = f(1) * 1 + f(2) * 2 = 2 * 1 + 4 * 1
using namespace std;
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 1)
            return k;
        if (n == 2)
            return k * k;
        int pre1 = k, pre2 = k * k;
        int t = 0;
        for (int i = 3; i <= n; i++)
        {
            t = (pre1 + pre2) * (k - 1);
            pre1 = pre2;
            pre2 = t;
        }
        return t;
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
