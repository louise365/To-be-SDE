// leetcode_1176.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
//#include <queue>
using namespace std;

class Solution {
public:
	int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
		int sum = 0;
		int tot = 0;
		for (auto i = 0; i < calories.size(); i++)
		{
			if (i <= k - 1)
				sum += calories[i];
			if (i == k - 1)
			{
				if (sum < lower)
					tot--;
				if (sum > upper)
					tot++;
			}
			else if (i > k - 1)
			{
				sum -= calories[i - k];
				sum += calories[i];
				if (sum < lower)
					tot--;
				if (sum > upper)
					tot++;
			}
		}
		return tot;
	}
};

int main()
{
	Solution s;
	vector<int> vt;
	vt = { 1,2,3,4,5 };
	cout << s.dietPlanPerformance(vt, 1, 3, 3) << endl;
	vt = { 3,2 };
	cout << s.dietPlanPerformance(vt, 2, 0, 1) << endl;
	vt = { 6,5,0,0 };
	cout << s.dietPlanPerformance(vt, 2, 1, 5) << endl;
	return 0;
}

