// leetcode_1056.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class Solution {
    char map[256];
public:
    bool confusingNumber(int N) {
        char map[256] = { 0 };
        map['0'] = '0';
        map['1'] = '1';
        map['6'] = '9';
        map['8'] = '8';
        map['9'] = '6';
        queue<int> vt;
        int t = N;
        while (t)
        {
            if (map[t % 10+'0'] == 0)
                return false;
            vt.push(t % 10);
            t /= 10;
        }
        while (vt.size())
        {
            t = map[vt.front() + '0'] - '0' + t * 10;
            vt.pop();
        }
        return t != N;
    }
};
int main()
{
    Solution s;
    s.confusingNumber(6);
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
