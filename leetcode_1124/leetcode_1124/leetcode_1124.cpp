// leetcode_1124.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
//dp[0] = vt[i+1] > 8 ? 1:-1;
//dp[i+1] = dp[i] + vt[i+1] > 8 ? 1:-1;
//if dp[i+1] >= 0 -> continue;
//else calculate count and reset temp count
//ret = max count -1;

class Solution1 {
public:
	int longestWPI(vector<int>& hours) {
		int ret = 0;
		int idx = 0;
		int dp[2] = { 0 , 0 };
		for (int i = 0; i < hours.size(); i++)
		{
			dp[1] = dp[0] + (hours[i] > 8 ? 1 : -1);
			if (dp[1] > 0 && ret < i - idx + 1)
				ret = i - idx + 1;
			if (dp[1] < 0)
			{
				idx = i + 1;
				dp[1] = 0;
			}
			dp[0] = dp[1];
		}
		return ret;
	}
};

class Solution2 {
public:
	int longestWPI(vector<int>& hours) {
		int len = 0;
		for (int i = 0; i < hours.size(); i++)
		{
			int t = find(hours, i);
			len = len < t ? t : len;
		}
		return len;
	}
	int find(vector<int>& hours, int idx)
	{
		int idx1 = idx, idx2 = idx;
		if (hours[idx] <= 8)
			return 0;
		int count = 1;
		int len = 1;
		bool s = true, e = true;
		while (1)
		{
			idx1--;
			idx2++;
			if (idx1 < 0 && idx2 >= hours.size())
				break;
			if (idx1 < 0)
			{
				idx1 = 0;
				s = false;
			}
			if (idx2 >= hours.size())
			{
				idx2 = hours.size() - 1;
				e = false;
			}
			count += (s ? (hours[idx1] > 8 ? 1 : -1) : 0) + (e ? (hours[idx2] > 8 ? 1 : -1) : 0);
			if (count > 0)
				len = len > (idx2 - idx1 + 1) ? len : (idx2 - idx1 + 1);
			else if (count == 0)
				continue;
			else
				break;
		}
		return len;
	}
};
class Solution {
public:
	int longestWPI(vector<int>& hours) {
		vector<int> vt = { 0 };
		int len = 0;
		stack<int> st;
		for (int i = 0; i < hours.size(); i++)
		{
			vt.push_back((hours[i] > 8 ? 1 : -1) + vt[i]);
			if (i == 0 || vt[i] < vt[st.top()])
				st.push(i);
		}
		int i = vt.size() - 1;
		
		for (int i = vt.size() - 1; i >= 0 && st.size(); i--)
		{
			while (st.size())
			{
				if (vt[i] > vt[st.top()])
				{
					len = max(len, i - st.top());
					st.pop();
				}
				else
					break;
			}
		}
		return len;
	}
};

int main()
{
	Solution s;
	vector<int> vt;
	vt = { 9,9,6,0,6,6,9 };//0,1,2,1,0,-1,0
	cout << s.longestWPI(vt) << endl;
	vt = { 9,6,9 };//(0,1,0,1)
	cout << s.longestWPI(vt) << endl;
	vt = { 6,9,9 };//(0,-1,-2,-1)
	cout << s.longestWPI(vt) << endl;
	//system("pause");
	return 0;
}

