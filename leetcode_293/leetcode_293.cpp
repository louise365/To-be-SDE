// leetcode_293.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<string> generatePossibleNextMoves(string s) {
		vector<string> vt;
		if (s.size() < 2)
			return vt;
		for (int i = 0; i < s.size()-1; i++)
		{
			if (s[i] == '+' && s[i + 1] == '+')
			{
				s[i] = s[i + 1] = '-';
				vt.push_back(s);
				s[i] = s[i + 1] = '+';
			}
		}
		return vt;
	}
};
int main()
{
	Solution s;
	s.generatePossibleNextMoves("++++");
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
