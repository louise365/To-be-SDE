// leetcode_1439.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	int add(int a, int b) {
		unsigned int carry = (unsigned int)(a & b) << 1U;
		unsigned int ret = a ^ b;
		while (carry)
		{
			unsigned int tmp = ret;
			ret = ret ^ carry;
			carry = (tmp & carry) << 1;
		}
		return int(ret);
	}
};
int main()
{
	Solution s;
	cout << s.add(1009, 2001) << endl;
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
