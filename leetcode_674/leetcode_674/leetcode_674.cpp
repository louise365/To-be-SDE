// leetcode_674.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int max_count = 0;
		int count = 0;
		int c = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] <= c)
			{
				max_count = max(max_count, count);
				c = INT_MIN;
				count = 0;
			}
			c = nums[i];
			count++;
		}
		return max(max_count,count);
	}
};

int main()
{
	Solution s;
	vector<int> v = {1,3,5,4,7};
	vector<int> v1 = { 2,2,2,2,2 };
	cout << s.findLengthOfLCIS(v) << endl;
	cout << s.findLengthOfLCIS(v1) << endl;
    return 0;
}

