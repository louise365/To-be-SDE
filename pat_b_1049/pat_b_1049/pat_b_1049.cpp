// pat_b_1049.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<double> vt;
	for (int i = 0; i < n; i++)
	{
		double t;
		cin >> t;
		vt.push_back(t);
	}
	double sum = 0;
	int len = vt.size();
	for (int i = 1; i <= len; i++)
		sum += vt[i - 1] * (len + 1 - i)*(i);
	sum += 0.005;
	printf("%.02lf\n", sum);
    return 0;
}

