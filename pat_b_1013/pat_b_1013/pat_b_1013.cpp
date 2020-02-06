// pat_b_1013.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, m;
	cin >> m >> n;
	vector<int> st = { 2 };
	int count = 1;
	int base = 3;
	while (1)
	{
		int t = sqrt(base);
		int flag = false;
		for (int j = 0; j < st.size(); j++)
		{
			if (base % st[j] == 0)
			{
				flag = true;
				break;
			}
		}
		for (int j = st[st.size() - 1]; j <= t; j++)
			if (base % j == 0)
			{
				flag = true;
				break;
			}
		if (!flag && base != 2)
		{
			st.push_back(base);
			if (++count > n)
				break;
		}
		base+=2;
	}

	count = 0;
	for (int i = m-1; i <=n-1; i++)
	{
		cout << st[i];
		if (++count % 10 && i!=n-1)
			cout << " ";
		else
			cout << endl;
	}
    return 0;
}

