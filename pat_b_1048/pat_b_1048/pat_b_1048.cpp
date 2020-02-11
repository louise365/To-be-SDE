// pat_b_1048.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int len = int(s2.size()) - int(s1.size());
	for (int i = 0; i < -len; i++)
		s2.insert(s2.begin(), '0');
	for (int i = 0; i < len; i++)
		s1.insert(s1.begin(), '0');
	bool flag = true;
	for (int i = 0; i < s1.size(); i++)
	{
		char sum;
		if ((s1.size() - i) & 1)
		{
			sum = (s1[i] - '0') + (s2[i] - '0');
			sum = sum % 13;
			if (sum == 10)
				sum = 'J';
			else if (sum == 11)
				sum = 'Q';
			else if (sum == 12)
				sum == 'K';
			else
				sum += '0';
		}
		else
		{
			int s = int(s2[i]) - int(s1[i]);
			s = (s < 0 ? (s + 10) : s) + '0';
			sum = s;
		}
	/*	if (flag)
		{
			if (sum == '0')
			{
				if (i == s1.size() - 1)
					printf("0");
			}
			else
			{
				flag = false;
				printf("%c",sum);
			}
		}
		else*/
			printf("%c", sum);
	}
	printf("\n");
    return 0;
}

