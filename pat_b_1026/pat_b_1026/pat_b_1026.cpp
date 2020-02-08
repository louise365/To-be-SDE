// pat_b_1026.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long c1, c2;
	long long c3;
	cin >> c1 >> c2;
	c3 = double(c2 - c1)/100.0 + 0.5;
	int hour = c3 / 3600;
	int minute = (c3 % 3600) / 60;
	int second = c3 % 60;
	printf("%02d:%02d:%02d\n", hour, minute, second);
	/*
	cout.width(2);
	cout.fill('0');
	cout << c3 / 3600 << ":" << c3 % 3600 / 60 << ":" << c3 % 60 << endl;
	*/
	/*
	string c1, c2;
	cin >> c1 >> c2;
	reverse(c1.begin(), c1.end());
	reverse(c2.begin(), c2.end());
	int remain = 0;
	for (int i = 0; i<c2.size(); i++)
	{
		if (i < c1.size())
		{
			if (remain + c1[i] >= c2[i])
			{
				c1[i] = remain + c1[i] - c2[i];
				remain = 0;
			}
			else
			{
				c1[i] = 10 + remain + c1[i] - c2[i];
				remain = -1;
			}
		}
		else
		{
			if (remain + c1[i] >= 0)
			{
				c1[i] = remain = c1[i];
				remain = 0;
			}
			else
			{
				c1[i] = 10 + remain + c1[i];
				remain = -1;
			}
		}
	}*/
    return 0;
}

