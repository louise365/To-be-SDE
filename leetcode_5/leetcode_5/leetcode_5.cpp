// leetcode_5.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

bool isPalindromic(string s)
{
	string::size_type i;
	for(i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-1-i])
			return false;
	}
	if(i == s.size()/2)
		return true;
	return false;
}

class Solution1 {
public:
    string longestPalindrome(string s) {
	
		string::iterator iter_i,iter_j;
		string maxs;
		string::size_type maxLen = 0;
		string::size_type i,j;
		//for(iter_i=s.begin();iter_i!=s.end();iter_i++)
		for(i=0;i<s.size();i++)
		{
			//for(iter_j=iter_i;iter_j!=s.end();iter_j++)
			for(j=i+1;j<=s.size();j++)
			{
				//if(iter_j - iter_i <= maxLen && maxLen)	continue;
				if(j - i + 1 <= maxLen && maxLen)	continue;
				string subs = s.substr(i,j-i+1);
				//string subs(iter_i,iter_i+1);
				if(isPalindromic(subs))
				{
						if(maxLen < subs.size())
						{
							maxLen = subs.size();
							maxs = subs;
						}
				}
			}
		}
		if(maxLen)
			return maxs;
		else
			return "";
    }
};

class Solution 
{
public:
    string longestPalindrome(string s) 
	{
		int i,j;
		int maxlen = 0;
		string maxs;
		for(i=0,j=0;i<s.size();i++)
		{
			j= 0;
			while(i-j >=0 && i+j <s.size())
			{
				if(s[i-j] == s[i+j])
				{
					if((2*j+1) > maxlen)
					{
						maxs = s.substr(i-j,2*j+1);
						maxlen = 2*j+1;
					}
					j++;
				}
				else
					break;
			}
		}
		for(i=0,j=0;i<s.size();i++)
		{
			j= 0;
			while(i-j >=0 && i+j+1 <s.size())
			{
				if(s[i-j] == s[i+j+1])
				{
					if((2*j+2) > maxlen)
					{
						maxs = s.substr(i-j,2*j+2);
						maxlen = 2*j+2;
					}
					j++;
				}
				else
					break;
			}
		}
		return maxs;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	cout<<s.longestPalindrome("a")<<endl;
cout<<s.longestPalindrome("babad")<<endl;
	cout<<s.longestPalindrome("abcdbbfcba")<<endl;
	return 0;
}

