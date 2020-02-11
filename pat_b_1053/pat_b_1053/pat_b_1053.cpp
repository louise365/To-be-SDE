// pat_b_1053.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, d;
	double e;
	cin >> n >> e >> d;
	double count[2] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		double ek;
		int countd = 0;
		for (int j = 0; j < k; j++)
		{
			cin >> ek;
			if (ek < e)
				countd++;
		}
		if (countd > k / 2)
		{
			if (k > d)
				count[1]+=1;
			else
				count[0]+=1;
		}
	}
	printf("%.01lf%% %.01lf%%\n",count[0]/n*100, count[1] / n * 100);

    return 0;
}

