// leetcode_415.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	string addStrings(string num1, string num2) {
		if (num1.size() < num2.size())
			swap(num1, num2);
		int remain = 0;
		int idx = 0;
		for (idx = 0; idx < num2.size(); idx++)
		{
			int t = num1[num1.size() - 1 - idx] - '0';
			num1[num1.size() - 1 - idx] = ((remain + t + num2[num2.size() - 1 - idx] - '0') % 10) + '0';
			remain = (remain + t + num2[num2.size() - 1 - idx] - '0') / 10;
		}
		while (remain)
		{
			if (idx < num1.size())
			{
				int t = num1[num1.size() - 1 - idx] - '0';
				num1[num1.size() - 1 - idx] = ((remain + t) % 10) + '0';
				remain = (remain + t) / 10;
				idx++;
			}
			else
			{
				num1.insert(num1.begin(), remain + '0');
				remain = 0;
			}
		}
		return num1;
	}
};
int main()
{
	Solution s;
	cout << s.addStrings("2", "999") << endl;
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
