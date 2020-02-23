// PAT_1002.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	map<int,double> mp;
	int m,n;
	while(cin>>m)
	{
		int i;
		int k;
		for(i=0;i<m;i++)
		{
			cin >> k;
			cin >> mp[k];
		}
		cin >> n;
		double val;
		map<int ,double>::iterator iter;
		for(i=0;i<n;i++)
		{
			cin >> k;
			cin >> val;
			iter = mp.find(k);
			if(iter != mp.end())
				mp[k] += val;
			else
			{
				mp[k] = val;
			}
		}
		
		int count = 0;
		for(iter = mp.begin();iter!=mp.end();iter++)
			if(iter->second != 0)
				count++;
		cout << count;
		map<int ,double>::reverse_iterator riter;
		for(riter = mp.rbegin();riter != mp.rend();riter++)
			if(riter->second != 0)
				cout << " " << riter->first << " " << fixed << setprecision(1) << riter->second;
	}
	return 0;
}

