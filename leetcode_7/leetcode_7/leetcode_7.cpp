// leetcode_7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <limits>
#include <math.h>
#include <iostream>
using namespace std;
int reverse(int x) {
	if (!x)  return 0;
	int stack[65] = { 0 };
	int index = 0;
	int result = 0;
	int _x = x;
	while (x != 0)
	{
		stack[index++] = x % 10;
		x /= 10;
	}
	for (int i = 0; i<index; i++)
	{
		result += stack[i] * pow(10.0, index - i - 1);
		if (result <= INT_MIN || result >= INT_MAX)
			return 0;
	}
	return result;
}

int main()
{
	cout << reverse(-123) << endl;
    return 0;
}

