// leetcode_53.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution1 {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		vector<int> presum = { 0 };
		stack<int> st;
		for (int i = 0; i < nums.size(); i++)
		{
			presum.push_back(presum[i] + nums[i]);
			if (!st.size())
				st.push(i);
			else
				if (presum[st.top()] > presum[i])
					st.push(i);
		}
		int len = 0;
		int maxsum = INT_MIN;
		for (int i = presum.size() - 1; i >= 1 && st.size(); i--)
		{
			while (st.size() && st.top() > i)
				st.pop();
			while (st.size() && presum[i] - presum[st.top()] > maxsum)
			{
				if (st.top() == i)
				{
					maxsum = max(maxsum, nums[i - 1]);
					st.pop();
				}
				else
					maxsum = max(maxsum,presum[i] - presum[st.top()]);
			}
		}
		return maxsum;
	}
};

//max(i-1)>0 max(i) = max(i-1)+nums[i]
//max(i-1)<=0 max(i) = nums[i]
//sum = max(max(i))
//sum means the max(i-1)
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ret = nums[0];
		int sum = nums[0];
		for (auto i = 1; i < nums.size(); i++)
		{
			if (sum > 0)
				sum = nums[i] + sum;
			else
				sum = nums[i];
			ret = max(ret, sum);
		}
		return ret = max(ret, sum);
	}
};

int main()
{
	Solution s;
	vector<int> vt;
	vt = { -1,-2 };
	//vt = { -2,1,-3,4,-1,2,1,-5,4 };
	//vt = {-1,-2,-3,0};
	//0,-1,-3,-6,-6
	//vt = { -1 };
	//vt = { -2,1 };
	//0,-2,-1
	//0,1,0
	//presum = -2,-1,-4,0,-1,1,2,-3,1
	//st = -2,-4
	cout << s.maxSubArray(vt) << endl;
	return 0;
}

