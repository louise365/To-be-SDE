// leetcode_205.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int map[128] = { 0 };
		for (int i = 0; i < s.size(); i++)
		{
			if (map[s[i]])
			{
				if (map[s[i]] == t[i])
					continue;
				else
					return false;
			}
			else
			{
				for (int j = 0; j < 128; j++)
				{
					if (map[j] == t[i] && j != s[i])
						return false;
				}
				map[s[i]] = t[i];
			}
		}
		return true;
	}
};
int main()
{
	Solution s;

	cout << s.isIsomorphic("bar", "foo") << endl;
	cout << s.isIsomorphic("ab", "ca") << endl;
	cout << s.isIsomorphic("egg", "add") << endl;
	cout << s.isIsomorphic("foo", "bar") << endl;
	cout << s.isIsomorphic("paper", "title") << endl;
	cout << s.isIsomorphic("","") << endl;
    return 0;
}

