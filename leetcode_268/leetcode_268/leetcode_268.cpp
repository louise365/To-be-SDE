// leetcode_268.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		//int _max = INT_MIN;
		//for (int i = 0; i < nums.size(); i++)
			//_max = max(_max, nums[i]);

		unsigned long long sum = ((nums.size()) * (nums.size() + 1)) >> 1;
		for (int i = 0; i < nums.size(); i++)
			sum -= nums[i];
		return sum;
	}
};

class Solution1 {
public:
	int missingNumber(vector<int>& nums) {
		int *map = new int[nums.size()+2];
		memset(map, 0, sizeof(int)*(nums.size() + 2));
		for (int i = 0; i < nums.size(); i++)
			map[nums[i]] = 1;
		for (int i = 0; i < nums.size() + 1; i++)
			if (!map[i])
			{
				delete(map);
				return i;
			}
	}
};
int main()
{
	Solution s;
	vector<int> vt = {0};
	cout << s.missingNumber(vt) << endl;
	vt.clear();
	vt = { 9,6,4,2,3,5,7,0,1 }; 
	cout << s.missingNumber(vt) << endl;
    return 0;
}

