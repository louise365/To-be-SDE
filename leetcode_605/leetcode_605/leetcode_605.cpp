// leetcode_605.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
/*
0 - two ends 0, one end 0, non-end 0
1 - two ends 1, one end 0, non-end 0
2 - two ends 1, one end 1, non-end 0
3 - two ends 2, one end 1, non-end 1
4 - two ends 2, one end 2, non-end 1
5 - two ends 3, one end 2, non-end 2
6 - two ends 3, one end 3, non-end 2
7 - two ends 4, one end 3, non-end 3
two ends -> (n+1)/2
one end -> n - (n+1)/2
non-end -> (n+1)/2-1
*/
class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int ret = 0;
		for (int i = 0; i < flowerbed.size(); i++)
		{
			if (flowerbed[i] == 0)
			{
				if ((flowerbed.size() == 1) ||
					(i == 0 && flowerbed[i + 1] == 0))
				{
					flowerbed[i] = 1;
					ret++;
					continue;
				}
				if(i == flowerbed.size() - 1)
					if (flowerbed[i - 1] == 0)
					{
						flowerbed[i] = 1;
						ret++;
						continue;
					}
				if(i>0 && i < flowerbed.size()-1)
					if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
					{
						flowerbed[i] = 1;
						ret++;
						continue;
					}
			}
		}
		return ret >= n;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1,0,1,0,1};
	vector<int> v1 = { 1,0,0,0,0,0,1 };

	vector<int> v2 = { 0,0,0 };
	vector<int> v3 = { 0};
	vector<int> v4 = { 0,1,0};
	cout << s.canPlaceFlowers(v4,1) << endl;
    return 0;
}

