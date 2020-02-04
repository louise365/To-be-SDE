// leetcode_169.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int> mp;
		vector<int>::iterator iter;
		for (iter = nums.begin(); iter != nums.end(); iter++)
		{
			map<int, int>::iterator it = mp.find((*iter));
			if (it == mp.end())
				mp.insert(make_pair((*iter), 1));
			else
				(*it).second++;
		}
		map<int, int>::iterator it1;
		int count = 0;
		int ret = 0;
		for (it1 = mp.begin(); it1 != mp.end(); it1++)
		{
			if ((*it1).second > count)
			{
				count = (*it1).second;
				ret = (*it1).first;
			}
		}
		return ret;
	}
};

int main()
{
    return 0;
}

