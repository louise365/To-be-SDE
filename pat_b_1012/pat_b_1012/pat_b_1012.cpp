// pat_b_1012.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <limits>
#include <cstdio>
using namespace std;

int main()
{
	int n,_n;
	long long a[4] = {0};
	double a3 = 0;
	int count3 = 0;
	int count2 = 0;
	int flag = 0;
	cin >> n;
	_n = n;
	while (_n--)
	{
		int t;
		cin >> t;
		if (t % 10 == 0)
			a[0] += t;
		if (t % 5 == 1)
			a[1] += ((++count2 & 1) ? 1 : -1) * t;
		if (t % 5 == 2)
			a[2]++;
		if (t % 5 == 3)
		{
			//a3 = (a3 * count3 + t) / (count3 + 1);
			a3 += t;
			count3++;
		}
		if (t % 5 == 4)
		{
			if (!flag)
			{
				a[3] = t;
				flag = !flag;
			}
			else
				if (t > a[3])
					a[3] = t;
		}
	}
	if (a[0])
		cout << a[0] << " ";
	else
		cout << "N ";
	if (count2)
		cout << a[1] << " ";
	else
		cout << "N ";
	if (a[2])
		cout << a[2] << " ";
	else
		cout << "N ";
	if (count3)
		//printf("%0.1f ",a3/count3+0.05);
		//printf("%0.1f ", a3 / count3);
	//should deal with double accuracy,but the question sucks
	//also the cout precision needs to be recover after used
	//use fixed to fill the zeros
	{
		cout.precision(1);
		cout << fixed << a3 / count3 << " ";
		cout.precision(6);
	}
	else
		cout << "N ";
	if (a[3])
		cout << a[3] << endl;
	else
		cout << "N" << endl;
    return 0;
}

