// pat_b_1020.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct store {
	double total;//need to be careful with the question content
	double price;//need to be careful with the question content
	double perPrice;
	friend bool operator < (store a, store b)
	{
		return a.perPrice > b.perPrice;
	}
};
int main()
{
	int n;
	int d;
	cin >> n >> d;
	int t, p;
	vector<store> storeList;
	for (int i = 0; i < n; i++)
	{
		store s;
		cin >> s.total;
		storeList.push_back(s);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> storeList[i].price;
		double tp = storeList[i].price;
		double tt = storeList[i].total;
		storeList[i].perPrice = tp / tt;
	}
	sort(storeList.begin(), storeList.end());
	double income = 0;
	int idx = 0;
	while (1)
	{
		if (d >= storeList[idx].total)
		{
			d -= storeList[idx].total;
			income += storeList[idx].price;
		}
		else
		{
			income += storeList[idx].perPrice * d;
			d = 0;
		}
		if (++idx >= storeList.size())
			break;
	}
	cout.precision(2);
	cout << fixed << income << endl;
	//system("pause");
    return 0;
}

