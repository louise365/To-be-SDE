// leetcode_1452.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
private:
	unordered_map<int, int> found;
	unordered_map<int, int>::iterator it;
public:
	int massage(vector<int>& nums) {
		found.clear();
		return find(nums, 0);
	}
	int find(vector<int>& nums, int i)
	{
		if (nums.size() == 0)
			return 0;
		//nums[i] + find(i + 2);
		//find(i + 1);
		it = found.find(i);
		if (it != found.end())
			return (*it).second;
		int ret = 0;
		if (i == nums.size() - 1)
			ret = nums[i];
		else if (i == nums.size() - 2)
			ret = max(nums[i], find(nums, i + 1));
		else
			ret = max(nums[i] + find(nums, i + 2), find(nums, i + 1));
		found.insert(make_pair(i, ret));
		return ret;
	}
};

int main()
{
	Solution s;
	vector<int> vt;
	vt = { 1,2,3,1 };
	cout << s.massage(vt) << endl;
	vt = { 2,7,9,3,1 };
	cout << s.massage(vt) << endl;
	vt = { 2,1,4,5,3,1,1,3 };
	cout << s.massage(vt) << endl;
	vt = { 1 };
	cout << s.massage(vt) << endl;
	return 0;
}

