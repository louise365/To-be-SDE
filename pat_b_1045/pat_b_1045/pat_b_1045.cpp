	// pat_b_1045.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, bool>> vt;
	int t;
	int _max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		vt.push_back(make_pair(t,t>_max));
		if (t > _max)
			_max = t;
	}
	int _min = INT_MAX;
	vector<pair<int, bool>>::reverse_iterator rit;
	int count = 0;
	for (rit = vt.rbegin();rit!=vt.rend();rit++)
	{
		if ((*rit).second == true)
		{
			if ((*rit).first > _min)
				(*rit).second = false;
			else
				count++;
		}
		if (_min > (*rit).first)
			_min = (*rit).first;
	}
	cout << count << endl;
	vector<pair<int, bool>>::iterator it;
	int flag = false;
	for(it = vt.begin();it!=vt.end();it++)
		if ((*it).second)
		{
			if (!flag)
			{
				cout << (*it).first;
				flag = !flag;
			}
			else
				cout << " " << (*it).first;
		}
	cout << endl;
    return 0;
}

