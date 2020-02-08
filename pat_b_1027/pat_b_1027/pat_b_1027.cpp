// pat_b_1027.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <set>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	char c;
	cin >> N >> c;
	int M = 0;
	while (1)
	{
		if (2 * M*M - 1 > N)
		{
			M--;
			break;
		}
		else
			M++;
	}
	for (int i = 0; i < 2 * M - 1; i++)
	{
		for (int j = 0; j < M - 1 - abs(M - 1 - i); j++)
			putchar(' ');
		for (int j = 0; j < 2 * abs(M - 1 - i) + 1; j++)
			putchar(c);
		putchar('\n');
	}
	printf("%d", N - 2 * M * M + 1);
	return 0;
}
	/*
	int n;
	char c;
	cin >> n >> c;
	int m = 1;
	set<int> st;
	while (1)
	{
		int M = (m*m - 1) * 2 + 1;
		if (M > 2000)
			break;
		else
		{
			st.insert(M);
			m++;
		}
	}
	set<int>::iterator it = st.begin();
	int flag = false;
	while (it != st.end())
	{
		if (*it > n)
		{
			if (it != st.begin())
			{
				flag = true;
				it--;
			}
			break;
		}
		it++;
	}
	if (!flag)
	{
		flag = !flag;
		it = st.end();
		it--;
	}
	if (flag)
	{
		int _n = *it;
		_n = sqrt((_n - 1) / 2 + 1);

		for (int i = 0; i <_n; i++)
		{
			for (int j = 0; j < _n * 2 - 1; j++)
			{
				if (j < i || j>=_n*2-1-i)
					cout << " ";
				else
					cout << c;
			}
			cout << endl;
		}
		for (int i = _n-2; i >=0; i--)
		{
			for (int j = _n * 2 - 2; j >= 0; j--)
			{
				if (j < i || j >= _n * 2 - 1 - i)
					cout << " ";
				else
					cout << c;
			}
			cout << endl;
		}

		if(n-*it)
			cout << n - *it << endl;
	}
	else
		cout << n << endl;
	//system("pause");
    return 0;
}
*/
