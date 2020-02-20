// leetcode_70.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//1,(1) = 1;
//2,1(1)+1(1*2) = 2;
//3,1(1)+2(1*2) = 3;
//4,1(1)+3(1*2)+1(2*2) = 6
//5,1(1)+4(1*2)+3(2*2) = 12
//6,1(1)+5(1*2)+6(2*2)+1(3*2) = 13
//7,1(1)+6(1*2)+10(2*2)+ (3*2)

//s(n) = s(n-1) + ((n-1)&1)?1:2;
//n-1 == 2*a, s(n) = s(n-1)+1;
//n-1 == 2*a+1, 1
class Solution1 {
public:
	int climbStairs(int n) {
		double sqrt5 = sqrt(5);
		double ret = (pow((1 + sqrt5) / 2, n+1) - pow((1 - sqrt5) / 2, n+1)) / sqrt5;
		return int(ret);
	}
};
class Solution {
public:
	int climbStairs(int n) {
		int sum1, sum2;
		int ret;
		for (int i = 1; i <= n; i++)
		{
			if (i == 1)
				sum1 = sum2 = i;
			else if (i == 2)
				sum2 = 2;
			else
			{
				int t = sum2;
				sum2 = sum2 + sum1;
				sum1 = t;
			}
		}
		return sum2;
	}
};


int main()
{
	Solution s;
	cout << s.climbStairs(2) << endl;
	cout << s.climbStairs(3) << endl;
	return 0;
}

