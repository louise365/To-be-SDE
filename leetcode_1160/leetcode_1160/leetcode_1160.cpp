// leetcode_1160.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		int map[256] = { 0 },map1[256];
		for (int i = 0; i < chars.size(); i++)
			map[chars[i]]++;
		int ret = 0;
		for (int i = 0; i < words.size(); i++)
		{
			memcpy(map1, map, sizeof(map));
			int j;
			for (j = 0; j < words[i].size(); j++)
			{
				if (map1[words[i][j]]--)
					continue;
				else
					break;
			}
			if (j == words[i].size())
				ret += j;
		}
		return ret;
	}
};

int main()
{
	Solution s;
	vector<string> vt;
	vt = { "cat","bt","hat","tree" };
	string chars = "atach";
	cout << s.countCharacters(vt, chars) << endl;
	vt.clear();
	vt = { "hello","world","leetcode" };
	chars = "welldonehoneyr";
	cout << s.countCharacters(vt,chars) << endl;
	return 0;
}

