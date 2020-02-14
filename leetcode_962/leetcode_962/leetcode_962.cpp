// leetcode_962.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;
//solution1
//s[i] = a[i+1]>=a[i] ? 1: -1
//t:1,-1,1,-1,-1,1
//s:1, 0,1, 0,-1,0

//solution2
//      0  ... 50000
// NLogN
//[0]s  1 
//[0]e -1
//[1]s  4
//[1]e -1
//[2]s  3
//[2]e -1
//[N]s  
//[N]e 

class Solution1 {
public:
	int maxWidthRamp(vector<int>& A) {
		int len = 0;
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = i + 1; j < A.size(); j++)
				if (A[j] >= A[i])
					len = max(len, j - i);
		}
		return len;
	}
};

//0 ... 50000
//s[i] -> smallest index for the value smaller than A[i]
//
class Solution2 {
public:
	int maxWidthRamp(vector<int>& A) {
		int ret = 0;
		map<int, int> mp1,mp2;
		map<int, int>::iterator it,it2;
		//map<int, int>::reverse_iterator rit;
		for (int i = 0; i < A.size(); i++)
		{
			mp1.insert(make_pair(A[i], i));
			//it2 = upper_bound(mp1.begin(), mp1.end(), A[i]);
			it2 = mp1.upper_bound(A[i]);
			int idx = 50001;
			for (it = mp1.begin(); it != it2; it++)
			{
				if (idx > (*it).second)
					idx = (*it).second;
			}
			ret = max(ret, i - idx);
		}
		return ret;
	}
};

class Solution {
public:
	int maxWidthRamp(vector<int>& A) {
		stack<int> st;
		//A.push_back(50001);
		int ret = 0;
		for (int i = 0; i < A.size(); i++)
		{
			if ((st.size() && A[st.top()] >= A[i] )||
				st.size() == 0)
				st.push(i);
		}
		for (int i = A.size() - 1; i >= 0; i--)
		{
			while (st.size() && A[st.top()] <= A[i])
			{
				ret = max(ret, i - st.top());
				st.pop();
			}
		}
		return  ret;
	}
};

int main()
{
	Solution s;
	vector<int> vt;
	vt = { 6,0,8,2,1,5 };
	cout << s.maxWidthRamp(vt) << endl;
	vt = { 9,8,1,0,1,9,4,0,4,1 };
	cout << s.maxWidthRamp(vt) << endl;
    return 0;
}

