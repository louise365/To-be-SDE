// pat_b_1024.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	char sign1, sign2;
	char c;
	cin >> sign1;
	if (sign1 == '-')
		cout << sign1;
	deque<char> q;
	int idx = 0;
	while (c = cin.get())
	{
		if (c == '.')
		{
			idx = q.size();
			continue;
		}
		if (c == 'E')
			break;
		q.push_back(c);
	}
	cin >> sign2;
	int e = 0;
	while (c = cin.get())
	{
		if (c == '\n')
			break;
		else
			e = e * 10 + c - '0';
	}
	if (sign2 == '-')
		e = e * (-1);
	idx = idx + e;

	if (idx < 0)
	{
		for (int i = idx; i < 0; i++)
			q.push_front('0');
		q.push_front('.');
		q.push_front('0');
	}
	else
	{
		if (idx < q.size())
		{
			deque<char>::iterator it = q.begin();
			int count = 0;
			while (count++ < idx)
				it++;
			q.insert(it, '.');
		}
		for (int i = q.size(); i < idx; i++)
			q.push_back('0');
	}
	deque<char>::iterator it = q.begin();
	while (it != q.end())
	{
		cout << *it;
		it++;
	}

	cout << endl;
	//system("pause");
    return 0;
}

