// pat_b_1030.cpp : Defines the entry point for the console application.
// there is a leek for the solution of (idx1,idx2)->((idx1++,idx2),(idx1,idx2--))->(idx1++,idx2--), it is possible to have a solution that is idx1+2

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool check(vector<long long >& st, int a, int b,long long p)
{
	if (a <= b && a >= 0 && a < st.size() && b >= 0 && b < st.size())
		return (st[b] <= st[a] * p);
	else
		return false;
}

int main()
{
	long long n, p;
	vector<long long> list;
	cin >> n >> p;
	while (n--)
	{
		int tmp;
		cin >> tmp;
		list.push_back(tmp);
	}
	sort(list.begin(), list.end());

	unsigned int idx1 = 0, idx2 = list.size() - 1;
	unsigned int ret = 0;
	vector<long long>::iterator it;
	for (unsigned int i = 0; i < list.size(); i++)
	{
		it = upper_bound(list.begin() + i+1, list.end(), list[i] * p);//it is the next postion of the found element
		unsigned int idx = it - list.begin() - i;
		ret = max(ret, idx);
	}
	
	cout << ret << endl;
    return 0;
}

