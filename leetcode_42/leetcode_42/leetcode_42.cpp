// leetcode_42.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

//i<j<k, min(h[i],h[k]) > h[j]
//find the next first element that is non smaller than the current smallest
//find the first one that is smaller than current
//stack big->small, right->left
class Solution {
public:
	int trap(vector<int>& height) {
		stack<int> st;
		vector<int> presum;
		int sum = 0;
		for (int i = 1; i < height.size(); i++)
		{
			if(height[i] > height[i-1])
		}
		//st.push(INT_MAX);
		int ret = 0;
		for (int i = 0; i < height.size(); i++)
		{
			while ()
			{

			}
			st.push(i);
		}
		return  ret;
	}
};

int main()
{
	Solution s;
	vector<int> vt = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << s.trap(vt) << endl;
    return 0;
}

