// leetcode_557.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
class Solution {
public:
	string reverseWords(string s) {
		string tmp;
		istringstream iss(s);
		ostringstream oss;
		while (iss >> tmp)
		{
			reverse(tmp.begin(), tmp.end());
			//tmp.reserve();
			oss << tmp;
			if (oss.str().size() != s.size())
				oss << " ";
		}
		tmp = oss.str();
		return  tmp;
	}
};

int main()
{
	Solution s;
	cout << s.reverseWords("Let's take LeetCode contest") << endl;
    return 0;
}

