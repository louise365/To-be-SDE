// pat_b_1046.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int count[2] = { 0 };
	int a1, a2, b1, b2;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
		if ((a2 == a1 + b1 && b2 == a1 + b1) ||
			(a2 != a1 + b1 && b2 != a1 + b1))
			continue;
		if(a2 != a1+b1)
			count[0]++;
		if (b2 != a1 + b1)
			count[1]++;
	}
	printf("%d %d\n", count[0],count[1]);
    return 0;
}

