// leetcode_443.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	int compress(vector<char>& chars) {
		int idx = 0;
		int idx2 = 0;
		int count = 0;
		for (int k = 0; k < chars.size(); k++)
		{
			count++;
			if (chars[k] != chars[idx])
			{
				if (chars[k] != chars[idx])
					count--;
				chars[idx2++] = chars[idx];
				if (count > 1)
				{
					string s = "";// to_string(count);
					for (auto c : s)
						chars[idx2++] = c;
				}
				idx = k;
				count = 1;
			}
			if (k == chars.size() - 1)
			{
				chars[idx2++] = chars[idx];
				if (count > 1)
				{
					string s = "";// to_string(count);
					for (auto c : s)
						chars[idx2++] = c;
				}
				idx = k;
			}
		}
		return idx2;
	}
};
int main()
{
	Solution s;
	vector<char> vt;
	//vt = { 'a','b','b','b','b','b','b','b','b','b','b','b','b'};
	//cout << s.compress(vt) << endl;
	//vt = { 'a','a','b','b','c','c','c' };
	//cout << s.compress(vt) << endl;
	//vt = { 'a'};
	vt = { 'a','b','b','c' };
	cout << s.compress(vt) << endl;
    return 0;
}

