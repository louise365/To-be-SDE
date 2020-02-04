// leetcode_13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int ret = 0;
		if (LUT.size() == 0)
			GenerateLUT();
		for (size_t i = 0;i<s.size();i++)
		{
			string tmp;
			if (i + 1 != s.size())
				tmp = s.substr(i, 2);
			if (FindRoman(tmp, ret))
				i++;
			else
			{
				tmp = s[i];
				FindRoman(tmp,ret);
			}
		}
		return ret;
	}
private:
	bool FindRoman(string s, int &ret)
	{
		vector<pair<string, int>>::iterator iter1;
		for (iter1 = LUT.begin(); iter1 != LUT.end(); iter1++)
			if ((*iter1).first == s)
			{
				ret += (*iter1).second;
				return true;
			}
		return false;
	}
	vector<pair<string, int>> LUT;
	void GenerateLUT()
	{
		if (LUT.size() != 0)
			return;
		LUT.push_back(make_pair("I", 1));
		LUT.push_back(make_pair("IV", 4));
		LUT.push_back(make_pair("V", 5));
		LUT.push_back(make_pair("IX", 9));
		LUT.push_back(make_pair("X", 10));
		LUT.push_back(make_pair("XL", 40));
		LUT.push_back(make_pair("L", 50));
		LUT.push_back(make_pair("XC", 90));
		LUT.push_back(make_pair("C", 100));
		LUT.push_back(make_pair("CD", 400));
		LUT.push_back(make_pair("D", 500));
		LUT.push_back(make_pair("CM", 900));
		LUT.push_back(make_pair("M", 1000));
	}
};

int main()
{
	Solution s;
	cout << s.romanToInt("III") << endl;
	cout << s.romanToInt("IV") << endl;
	cout << s.romanToInt("IX") << endl;
	cout << s.romanToInt("LVIII") << endl;
	cout << s.romanToInt("MCMXCIV") << endl;
    return 0;
}

