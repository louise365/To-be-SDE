// pat_b_1056.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int map[11] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		map[t] = 1;
	}
	int ret = 0;
	for (int i = 0; i < 11; i++)
		if (map[i])
			ret += (n - 1)*i * 11;
	cout << ret << endl;
    return 0;
}

