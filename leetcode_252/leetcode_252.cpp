// leetcode_252.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int> a, vector<int>b)
{
    if (a[0] != b[0])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return true;
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < intervals.size() - 1; i++)
            if (intervals[i + 1][0] < intervals[i][1])
                return false;
        return true;
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
