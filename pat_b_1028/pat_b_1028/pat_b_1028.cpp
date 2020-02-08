// pat_b_1028.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	double _min = 201;
	double _max = -1;
	int count = 0;
	string name_min, name_max;
	char name[100];
	//string name,in;
	int year = 0, month = 0, day = 0;
	double age;
	while (n--)
	{ 
		scanf("%s %d/%d/%d",name,&year,&month,&day);
		if (year < 1814)
			continue;
		else if(year == 1814)
		{
			if (month < 9)
				continue;
			else if (month == 9)
			{
				if (day < 6)
					continue;
			}
		}
		if (year > 2014)
			continue;
		else if(year == 2014)
		{
			if (month > 9)
				continue;
			else if (month == 9)
			{
				if (day > 6)
					continue;
			}
		}
		age = double(year - 1814) + double(month - 9) / 12 + double(day - 6) / 365;
		if (age < _min)
		{
			_min = age;
			name_min = name;
		}
		if (age > _max)
		{
			_max = age;
			name_max = name;
		}
		count++;
	}
	cout << count;
	if (_max != -1)
		cout << " " << name_min;
	if (_min != 201)
		cout << " " << name_max;
	cout << endl;
	//cout << count << " " << name_min << " " << name_max << endl;

    return 0;
}

