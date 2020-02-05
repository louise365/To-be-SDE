// leetcode_56.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		//if (intervals.size() == 1)
			//return intervals;
		vector<vector<int>> ret;
		sort(intervals.begin(), intervals.end());
		int s = intervals[0][0], e = intervals[0][1];
		
		for (int i = 1; i < intervals.size(); i++)
		{
			if (e < intervals[i][0])
			{
				vector<int> vt = {s,e};
				ret.push_back(vt);
				s = intervals[i][0];
				e = intervals[i][1];
			}
			else
			{
				e = max(e, intervals[i][1]);
			}
		}
		vector<int> vt = { s,e };
		ret.push_back(vt);
		return ret;
	}
};

int main()
{
	vector<vector<int>> vt, ret;
	vector<int> v0 = {1,3};
	vector<int> v1 = {2,6};
	vector<int> v2 = {8,10};
	vector<int> v3 = { 15,18 };
	vector<int> v4 = { 1,18 };
	vector<int> v5 = { 18,19 };
	vt.push_back(v5);
	vt.push_back(v4);
	//vt.push_back(v3);
	//vt.push_back(v2);
	//vt.push_back(v1);
	//vt.push_back(v0);
	Solution s;
	ret = s.merge(vt);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < ret[i].size(); j++)
			cout << ret[i][j] << " ";
		cout << "]" << endl;
	}
    return 0;
}

