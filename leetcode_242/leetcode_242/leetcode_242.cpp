// leetcode_242.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		transform(t.begin(), t.end(), t.begin(), ::tolower);
		int count[26] = { 0 };
		for (int i = 0; i < s.size(); i++)
			count[s[i] - 'a']++;
		for (int i = 0; i < t.size(); i++)
		{
			if (count[t[i] - 'a'])
				count[t[i] - 'a']--;
			else
				return false;
		}
		return true;
	}
};
int main()
{
	Solution s;
	cout << s.isAnagram("123","213") << endl;
    return 0;
}

