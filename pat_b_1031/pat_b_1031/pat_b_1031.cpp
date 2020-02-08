// pat_b_1031.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n,_n;
	cin >> n;
	_n = n;
	const int right[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char check[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
	vector<string> st;
	string in;
	while (n--)
	{
		cin >> in;
		int m = 0;
		int flag = true;
		for (int i = 0; i < 17; i++)
		{
			if (in[i] < '0' || in[i] > '9')
			{
				flag = false;
				break;
			}
			m = (m + right[i] * (in[i] - '0')) % 11;
		}
		if (in[17] != check[m] || !flag)
			st.push_back(in);
	}
	if (st.size() == 0)
		cout << "All passed" << endl;
	else
	{
		for (int i = 0; i < st.size(); i++)
			cout << st[i] << endl;
	}

    return 0;
}

