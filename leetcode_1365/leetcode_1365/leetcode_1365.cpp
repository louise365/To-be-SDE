// leetcode_1365.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution1 {
public:
	string compressString(string S) {
		string copy;
		char pre = S[0];
		int count = 0;
		for (auto i = 0; i < S.size(); i++)
		{
			char t = pre;
			pre = S[i];
			count++;
			if (S[i] != t)
			{
				copy += t + to_string(count - 1);
				count = 1;
			}
			if (i == S.size() - 1)
			{
				copy += S[i] + to_string(count);
			}
		}
		if (copy.size() >= S.size())
			return S;
		else
			return copy;
	}
};

class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> ret;
		if (nums.empty())
			return ret;
		vector<int> num(nums.begin(), nums.end());
		sort(num.begin(), num.end());
		map<int, pair<int,int>> mp;
		map<int, pair<int, int>>::iterator it;
		for (auto i : num) {
			it = mp.find(i);
			if (it == mp.end())
			{
				int pre = 0;
				if (mp.size())
					pre = mp.rbegin()->second.second + mp.rbegin()->second.first;
				mp.emplace(make_pair(i, make_pair(1,pre)));
			}
			else
				++it->second.first;
		}
		for (auto i : nums)
			ret.emplace_back(mp[i].second);
		return ret;
	}
};

int main()
{
	Solution s;
	vector<int> vt = { 8,1,2,2,3 };
	s.smallerNumbersThanCurrent(vt);
	//Solution1 s;
	//string _s = "aabcccccaaa";
//	cout << s.compressString(_s) << endl;
	return 0;
}

