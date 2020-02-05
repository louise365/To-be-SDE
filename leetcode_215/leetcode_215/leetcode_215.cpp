// leetcode_215.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
class Solution1 {
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}
};

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		multiset<int> vt;
		for (int i = 0; i < nums.size(); i++)
		{
			vt.insert(nums[i]);
			if (vt.size() > k)
			{
				vt.erase(vt.begin());
			}
		}
		return (*vt.begin());
	}
};

int main()
{
	Solution s;
	vector<int> vt = { 3,2,1,5,6,4 };
	int n = 2;
	cout << s.findKthLargest(vt, n) << endl;
    return 0;
}

