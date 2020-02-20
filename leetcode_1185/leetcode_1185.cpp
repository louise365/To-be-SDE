// leetcode_1185.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
private:
    int m[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int lut[13] = { 0 };
    string out[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
public:
    Solution()
    {
        for (int i = 1; i < 12; i++)
            lut[i] = lut[i - 1] + m[i - 1];
    }
    string dayOfTheWeek(int day, int month, int year) {
        //1971.1.1 Fri
        int sum = ((year - 1971) * 365 % 7) + lut[month - 1] + day - 1;
        int ret = 5 + sum % 7;
        int y = 1971;
        while (y < year)
        {
            if (y % 4 == 0)
            {
                if (y % 100 != 0 || y % 400 == 0)
                    ret++;
                y += 4;
            }
            else
                y++;
        }
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        {
            if (month > 2)
                ret++;
        }
        return out[ret % 7];
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
