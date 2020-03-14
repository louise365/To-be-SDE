// leetcode_169.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> mp;
		int n = nums.size();
		n = (n + 1) >> 1;
		int ret = 0;
		for (auto i:nums)
		{
			unordered_map<int, int>::iterator it = mp.find(i);
			if (it == mp.end())
				it = (mp.emplace(make_pair(i, 1))).first;
			else
				++it->second;
			if (it->second >= n)
			{
				ret = it->first;
				break;
			}
		}
		return ret;
	}
};

int main()
{
	Solution s;
	vector<int> vt = { 3,2,3 };
	s.majorityElement(vt);
    return 0;
}

