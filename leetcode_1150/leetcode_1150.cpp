// leetcode_1150.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	int count(vector<int>& nums, int target, int s, int e)
	{
		if (s == e)
			return nums[s] == target ? 1 : 0;
		int m = s + (e - s) / 2;
		if (nums[m] < target)
			return count(nums, target, m + 1, e);
		else if (nums[m] > target)
			return count(nums, target, s, m);
		else
			return count(nums, target, m + 1, e) + count(nums, target, s, m);
	}
public:
	bool isMajorityElement(vector<int>& nums, int target) {
		return count(nums, target, 0, nums.size() - 1) > nums.size() / 2;
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
