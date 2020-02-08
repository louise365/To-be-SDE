// pat_b_1043.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
using namespace std;

int main()
{
	int map[256] = { 0 };
	char c;
	int count = 0;
	while (c = getchar())
	{
		if (c == '\n')
			break;
		map[c]++;
		if(c == 'P' || c == 'A' || c == 'T' ||
			c == 'e' || c == 's' || c == 't')
			count++;
	}
	char out[10] = { 'P','A','T','e','s','t' };
	while (count)
	{
		for (int i = 0; i<6; i++)
			if (map[out[i]])
			{
				putchar(out[i]);
				map[out[i]]--;
				count--;
			}
	}
	printf("\n");
	return 0;
}

