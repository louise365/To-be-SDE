// pat_b_1036.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	char c;
	cin >> n >> c;
	for (int i = 0; i < (n+1)/2; i++)
	{
		if (i == 0 || i == (n + 1) / 2-1)
		{
			for (int j = 0; j < n; j++)
				printf("%c",c);
			printf("\n");
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				if (j == 0 || j == n - 1)
					printf("%c",c);
				else
					printf(" ");
			}
			printf("\n");
		}
	}
    return 0;
}

