// pat_b_1051.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	double R1, P1, R2, P2;
	scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);
	double A = R1*R2 *cos(P1+P2);// (cos(P1)*cos(P2) - sin(P1)*sin(P2));
	double B = R1*R2 *sin(P1 + P2);// (sin(P1)*cos(P2) + sin(P2)*cos(P1));

	if (abs(A) < 0.01)
		printf("0.00", abs(A));
	else
		printf("%0.2lf", A);
	if(abs(B) < 0.01)
		printf("+0.00i\n", abs(A));
	else
		printf("%c%.02lfi\n", (B>=0?'+':'-'),abs(B));
	return 0;
}

