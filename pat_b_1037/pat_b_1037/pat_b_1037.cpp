// pat_b_1037.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	long long g1, s1, k1, g2, s2, k2;
	scanf("%lld.%lld.%lld %lld.%lld.%lld",
		&g1, &s1, &k1, &g2, &s2, &k2);
	g1 = k1 + s1 * 29 + g1 * 17 * 29;
	g2 = k2 + s2 * 29 + g2 * 17 * 29;
	g1 = g2 - g1;
	if (g1 < 0)
	{
		printf("-");
		g1 = -g1;
	}
	printf("%lld.%lld.%lld\n",
		g1/(17*29),g1/29%17,g1%29);
    return 0;
}

