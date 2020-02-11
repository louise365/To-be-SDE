// pat_b_1055.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

struct p
{
	string name;
	int h;
	friend bool operator<(p a, p b)
	{
		if (a.h != b.h)
			return a.h > b.h;
		else
			return a.name < b.name;
	}
};

int main()
{
	int n, k;
	cin >> n >> k;
	vector<p> vt;

	deque<deque<p>> s;
	for (int i = 0; i < n; i++)
	{
		p _p;
		cin >> _p.name >> _p.h;
		if(_p.h>=30 && _p.h <=300)
			vt.push_back(_p);
	}
	sort(vt.begin(), vt.end());
	//mid -> left -> right
	int count = 0;
	int len = n / k;
	if (k == 1)
		len = len - 1;
	for (int i = len; i >= 0 && count<n; i--)
	{
		deque<p> q;
		int end;
		int start;
		if (i == len && k!=1)
		{
			start = len * (i>0?i---1:i);
			end = n;
		}
		else
		{
			start = len * i;
			end = (i + 1)*len;
		}
		int t = 0;
		for (int j = start; j < end && count<n; j++)
		{
			if (!(t&1))
				q.push_back(vt[count]);
			else
				q.push_front(vt[count]);
			t++;
			count++;
		}
		s.push_back(q);
	}
	deque<deque<p>>::iterator it;
	for (it = s.begin(); it != s.end(); it++)
	{
		while ((*it).size())
		{
			cout << (*it).front().name;
			(*it).pop_front();
			if ((*it).empty())
				cout << endl;
			else
				cout << " ";
		}
	}
	return 0;
}

