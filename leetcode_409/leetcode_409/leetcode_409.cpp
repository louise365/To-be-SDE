// leetcode_409.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
		int input[256] = {0};
		int i;
		for(i=0;i<s.size();i++)
			input[s[i]]++;
		bool found = false;
		int count = 0;
		
		for(i=0;i<256;i++)
		{
			if(!input[i])
				continue;
			if(input[i] & 1)
			{
				found = true;
				count += input[i]-1;
			}
			else
				count += input[i];
		}
		return count + (found?1:0);	
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	cout << s.longestPalindrome("abccccdd") << endl;
	return 0;
}

