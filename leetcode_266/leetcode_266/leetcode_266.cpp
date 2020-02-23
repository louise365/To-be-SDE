// leetcode_266.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
class Solution 
{
public:
    bool canPermutePalindrome(string s) 
	{
		string::size_type i;
		int count[26] = {0};
		for(i=0;i<s.size();i++)
		{
			count[s[i]-'a']++;
		}
		bool found = false;
		for(i=0;i<26;i++)
		{
			if(count[i] & 1)
				if(found)
					return false;
				else
					found = true;
		}
		return true;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	cout << s.canPermutePalindrome("code")<< endl;
	cout << s.canPermutePalindrome("aab") << endl;
	cout << s.canPermutePalindrome("carerac") << endl;
	return 0;
}

