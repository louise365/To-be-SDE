// leetcode_408.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool validWordAbbreviation(string word, string abbr) {
		int idx = 0;
		int count = 0;
		bool ret = true;
		for (int i = 0; i < abbr.size(); i++)
		{
			if (isalpha(abbr[i]))
			{
				if (count)
				{
					idx += count;
					count = 0;
					if (idx > word.size() - 1)
					{
						ret = false;
						break;
					}
				}
				if (word[idx++] != abbr[i])
				{
					ret = false;
					break;
				}
			}
			else
			{
				if (count == 0 && abbr[i] == '0')
				{
					ret = false;
					break;
				}
				count = count * 10 + abbr[i] - '0';
			}
		}
		if (count)
		{
			if (count + idx != word.size())
				ret = false;
		}
		return ret;
	}
};
int main()
{
	Solution s;
	cout << s.validWordAbbreviation("abc", "2") << endl;
	cout << s.validWordAbbreviation("internationalization", "i12iz4n") << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
