// pat_b_1034.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
	int t;
	while (a)
	{
		t = a;
		a = b%a;
		b = t;
	}
	return b;
}

void print(long long k1, long long a1, long long b1,
	long long k2, long long a2, long long b2,
	long long k3, long long a3, long long b3,
	char c)
{
	if (k1 == 0)
		printf("%lld/%lld %c ", a1, b1);
	else if (k1<0)
		printf("(%lld %lld/%lld) %c ", k1, a1, b1);
	else
		printf("%lld %lld/%lld %c ", k1, a1, b1, c);
	if(k2 == 0)
		printf("%lld/%lld = ", a2, b2);
	else if(k2<0)
		printf("(%lld %lld/%lld) = ", k2, a2, b2);
	else 
		printf("%lld %lld/%lld = ", k2, a2, b2);
	if (k2 == 0 && a2 == 0 && b2 == 0)
		printf("Inf\n");
	else
	{
		if(k3 == 0)
			printf("%lld/%lld\n", a3, b3);
		else if(k3<0)
			printf("(%lld %lld/%lld)\n", a3, b3);
		else
			printf("%lld %lld/%lld\n", a3, b3);
	}
}

int main()
{
	printf("%d\n", gcd(60, 100));
	long long a1, b1, a2, b2;
	long long a3, b3;
	scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
	//printf("%lld - %lld - %lld - %lld\n", a1, b1, a2, b2);
	long long k1 = a1 / b1;
	long long k2 = a2 / b2;
	long long _a1 = a1 % b1;
	long long _a2 = a2 % b2;
	//+
	a3 = a1 * b2 + a2 * b1;
	b3 = b1 * b2;
	long long k3 = a3 / b3;
	long long _a3 = a3 % b3;
	char c = '+';
	
    return 0;
}

