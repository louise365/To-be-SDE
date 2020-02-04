// leetcode_665.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		//array[i] <= array[i + 1], so only one item is allowed for array[i] > array[i + 1]
		if (nums.size() <= 2)
			return true;
		int count = 0;
		for (int i = 0; i < nums.size()-1; i++) {
			if (nums[i + 1] < nums[i]) {
				if (i == 0 || i+1 == nums.size() - 1)
					count++;
				else {
					if (nums[i - 1] > nums[i + 1])
						nums[i + 1] = nums[i];
					else
						nums[i] = nums[i - 1];
					count++;
				}
			}
			if (count > 1)
				return false;
		}
		return true;
	}
};
int main()
{
	Solution s;
	vector<int> vt = {4,2,3};
	vector<int> vt1 = { 4,2,1};
	vector<int> vt2 = { 2,3,3,2,4};
	vector<int> vt3 = { 2,3,4,2,2};
	cout << s.checkPossibility(vt) << endl;
	cout << s.checkPossibility(vt1) << endl;
	cout << s.checkPossibility(vt2) << endl;
	cout << s.checkPossibility(vt3) << endl;
    return 0;
}

