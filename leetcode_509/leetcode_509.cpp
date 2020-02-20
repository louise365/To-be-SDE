// leetcode_509.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    int fib(int N) {
        double sqrt5 = sqrt(5);
        double ret = (pow((1 + sqrt5) / 2, N) - pow((1 - sqrt5) / 2, N)) / sqrt5;
        return int(ret);
    }
};
int main()
{
    Solution s;
    cout << s.fib(4) << endl;
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
