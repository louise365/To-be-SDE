// leetcode_15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		sort(nums.begin(), nums.end());//O(NLogN)
		for (int i = 0; i < nums.size();)
		{
			int s = i + 1;
			int e = nums.size() - 1;
			while (1)
			{
				if (s >= nums.size() || s >= e)
					break;
				int sum2 = nums[i] + nums[s];
				if (sum2 < 0 && nums[e] < 0)
					break;
				if (sum2 > 0 && nums[e] > 0)
					break;
				int sum3 = sum2 + nums[e];
				if (sum3 == 0)
				{
					vector<int> rt = { nums[i],nums[s],nums[e] };
					ret.push_back(rt);
					int ns = s++;
					while (s < e)
					{
						if (nums[s] == nums[ns])
							s++;
						else
							break;
					}
				}
				else if (sum3 < 0)
					s++;
				else
					e--;
			}
			int ni = i++;
			
			while (i < nums.size())
			{
				if (nums[i] == nums[ni])
					i++;
				else
					break;
			}
			
		}
		return ret;
	}
};

int main()
{
	//vector<int> vt = { -1, 0, 1, 2, -1, -4 };
	//vector<int> vt = { -1,-1,0,1,1, 2, -1, -4 };
	vector<int> vt = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0 };
	//-4,-1,-1,-1,0,1,1,2
	Solution s;
	vector<vector<int>> ret = s.threeSum(vt);
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
			cout << ret[i][j] << " ";
		cout << endl;
	}
    return 0;
}

