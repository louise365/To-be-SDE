// leetcode_55.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution1 {
public:
	bool canJump(vector<int>& nums) {
		return DFS(nums,0);
	}
	bool DFS(vector<int>& nums, unsigned int idx) {
		if (nums[idx] >= 0)
		{
			if (nums.size() - 1 <= idx + nums[idx])
				return  true;
			else
			{
				for (unsigned int i = idx+1; i <= idx + nums[idx]; i++)
					if (DFS(nums,i))
						return  true;
				return  false;
			}
		}
		else
			return false;
	}
};
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int _max = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > _max)	return false;
			_max = max(_max, i + nums[i]);
			if (_max >= nums.size()-1)
				return true;
		}
		return false;
	}
};
int main()
{
	Solution s;
	vector<int> vt = { 2,3,1,1,4 };
	vector<int> vt1 = { 3,2,1,0,4 };
	cout << s.canJump(vt) << endl;
	cout << s.canJump(vt1) << endl;
    return 0;
}

