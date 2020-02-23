// leetcode_1271.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string toHexspeak(string num) {
		string str;
		int n = 0;//atoi(num.c_str());
		while (num.size())
		{
			n = n* 10 + num.back() - '0';
			num.pop_back();
			
		}
		reverse(str.begin(), str.end());
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '0')
				str[i] = 'O';
			if (str[i] == '1')
				str[i] = 'I';
			if (str[i] != 'A' && str[i] != 'B' && str[i] != 'C' && str[i] != 'D' &&
				str[i] != 'E' && str[i] != 'F' && str[i] != 'I' && str[i] != 'O')
				return "ERROR";
		}
		return str;
	}
};
int main()
{
	Solution s;
	s.toHexspeak("747823223228");
	std::cout << "Hello World!\n";
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
