// leetcode_256.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution1 {
private:
	unordered_map<unsigned long long, int> mp;
	unordered_map<unsigned long long, int>::iterator it;
	unsigned long long hash_key(int a, int b)
	{
		unsigned long long ret = a;
		ret = (ret << 32) + b;
		return ret;
	}
public:
	int minCost(vector<vector<int>>& costs) {
		mp.clear();
		return min(min(findMin(costs, 0, 0), findMin(costs, 0, 1)),
			findMin(costs, 0, 2));
	}
	int findMin(vector<vector<int>>& costs, int idx, int color)
	{
		string a = std::to_string(123);
		if (idx >= costs.size())
			return 0;
		it = mp.find(hash_key(idx,color));
		if (it != mp.end())
			return (*it).second;
		int minV = INT_MAX;
		for (int i = 0; i < costs[idx].size(); i++)
		{
			if (i == color)
				continue;
			if (costs.size() - 1 == idx)
				minV = min(costs[idx][i], minV);
			else
				minV = min(costs[idx][i] + findMin(costs, idx + 1, i), minV);
		}
		mp.insert(make_pair(hash_key(idx,color), minV));
		return minV;
	}
};

class Solution {
public:
	int minCost(vector<vector<int>>& costs) {
		int tc[3] = { 0 };
		for (auto i = 0; i < costs.size(); i++)
		{
			costs[i][0] += min(tc[1], tc[2]);
			costs[i][1] += min(tc[0], tc[2]);
			costs[i][2] += min(tc[0], tc[1]);
			tc[0] = costs[i][0];
			tc[1] = costs[i][1];
			tc[2] = costs[i][2];
		}
		return min(min(tc[0], tc[1]), tc[2]);
	}
};
int main()
{
	Solution s;
	vector<vector<int>> vt;
	vector<int> v;
	v = { 17,2,17 };
	vt.push_back(v);
	v = {16,16,5};
	vt.push_back(v);
	v = { 14,3,19 };
	vt.push_back(v);
	cout << s.minCost(vt) << endl;
	return 0;
}

