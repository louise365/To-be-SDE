// leetcode_371.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		int ret;
		unsigned int carry;
		while (1)
		{
			ret = a^b;
			carry = (a&b);
			carry<<= 1;
			a = ret;
			b = carry;
			if (!carry)
				break;
		}
		return ret;
	}
};

int main()
{
	Solution s;
	cout << s.getSum(2, 8) << endl;
	cout << s.getSum(-2, 2) << endl;
    return 0;
}

