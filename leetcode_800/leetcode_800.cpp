// leetcode_800.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    const int map[16] = { 0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,
    0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff };
    string GetMin(string str)
    {
        int t = 0;
        if (isdigit(str[0]))
            t = (str[0] - '0') * 16;
        else
            t = (str[0] - 'a' + 10) * 16;
        if (isdigit(str[1]))
            t += (str[1] - '0');
        else
            t += (str[1] - 'a' + 10);
        int idx = 0;
        int minV = INT_MAX;
        for (int i = 0; i < 16; i++)
        {
            if (minV > abs(t - map[i]))
            {
                idx = i;
                minV = abs(t - map[i]);
            }
        }
        //return -(minV ^ 2);
        char c1 = (map[idx] / 16 < 10) ? (map[idx] / 16 + '0') : (map[idx] / 16 - 10 + 'a');
        char c2 = (map[idx] % 16 < 10) ? (map[idx] % 16 + '0') : (map[idx] % 16 - 10 + 'a');
        string out;
        out = c1;
        out+=c2;
        return out;
    }
public:
    string similarRGB(string color) {
        return "#" + GetMin(color.substr(1, 2)) + GetMin(color.substr(3, 2)) + 
            GetMin(color.substr(5, 2));
    }
};
int main()
{
    Solution s;
    s.similarRGB("#09f166");
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
