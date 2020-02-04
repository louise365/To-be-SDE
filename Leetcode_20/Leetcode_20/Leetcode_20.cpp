// Leetcode_20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isValid(string s) 
	{
		vector<char> _stack;
		for (size_t i = 0; i < s.size(); i++)
		{
			vector<char>::reverse_iterator riter = _stack.rbegin();
			if (s[i] == '(')
				_stack.push_back('(');
			if (s[i] == '[')
				_stack.push_back('[');
			if (s[i] == '{')
				_stack.push_back('{');
			if (s[i] == ')')
			{
				if (riter == _stack.rend())
					return false;
				if ((*riter) != '(')
					return false;
				else
					_stack.pop_back();
			}
			if (s[i] == ']')
			{
				if (riter == _stack.rend())
					return false;
				if ((*riter) != '[')
					return false;
				else
					_stack.pop_back();
			}
			if (s[i] == '}')
			{
				if (riter == _stack.rend())
					return false;
				if ((*riter) != '{')
					return false;
				else
					_stack.pop_back();
			}
		}
		if (_stack.size() != 0)
			return false;
		return true;
	}
};
int main()
{
	Solution s;
	cout << s.isValid("()") << endl;
	cout << s.isValid("()[]{}") << endl;
	cout << s.isValid("(]") << endl;
	cout << s.isValid("([)]") << endl;
	cout << s.isValid("{[]}") << endl;
    return 0;
}

