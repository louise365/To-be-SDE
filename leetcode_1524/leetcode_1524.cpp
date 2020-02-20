// leetcode_1524.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//f(1) = (f(2) + m)%2
//f(n) = (f(n-1)+m)%(n-1)
#include <iostream>
class Solution {
public:
    int lastRemaining(int n, int m) {
        int f1 = 1;
        for (int i = 2; i <= n; i++)
            f1 = (f1 + m) % i;
        return f1;
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
