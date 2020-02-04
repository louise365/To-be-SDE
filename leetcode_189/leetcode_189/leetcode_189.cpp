// leetcode_189.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k = k%nums.size();
		if (nums.size() <= 1 || k==0)
			return;
		int s = nums.size() - k;
		vector<int> rt(nums);
		nums.clear();
		int i = 0;
		while (i++ < rt.size())
		{
			nums.push_back(rt[s++]);
			s = s%rt.size();
		}
	}
};

int main()
{
	Solution s;
	vector<int> input;
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);
	input.push_back(4);
	input.push_back(5);
	input.push_back(6);
	input.push_back(7);
	s.rotate(input, 3);
	//cout <<  input	<< endl;
    return 0;
}

