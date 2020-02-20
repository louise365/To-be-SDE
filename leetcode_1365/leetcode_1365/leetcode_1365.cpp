// leetcode_1365.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string compressString(string S) {
		string copy;
		char pre = S[0];
		int count = 0;
		for (auto i = 0; i < S.size(); i++)
		{
			char t = pre;
			pre = S[i];
			count++;
			if (S[i] != t)
			{
				copy += t + to_string(count - 1);
				count = 1;
			}
			if (i == S.size() - 1)
			{
				copy += S[i] + to_string(count);
			}
		}
		if (copy.size() >= S.size())
			return S;
		else
			return copy;
	}
};

int main()
{
	Solution s;
	string _s = "aabcccccaaa";
	cout << s.compressString(_s) << endl;
    return 0;
}

