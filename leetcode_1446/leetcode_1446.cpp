// leetcode_1446.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int k = nums.size()/2 + 1;
        unordered_map<int, int> mp;
        unordered_map<int, int>::iterator it;
        for (auto i : nums)
        {
            it = mp.find(i);
            if (it == mp.end())
                mp.insert(make_pair(i, 1));
            else
            {
                if (++(*it).second >= k)
                    return (*it).first;
            }
        }
        return -1;
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
