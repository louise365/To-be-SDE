// PAT_BASIC_1003.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cin>>n;;
	while(n--)
	{
		string s;
		cin >> s;
		
		int ip = s.find('P');
		int it = s.find('T');
		int ia = s.find('A');
		if(ip == s.npos || it == s.npos || ia == s.npos)
		{
			cout << "NO" << endl;
			continue;
		}
		int count1 = 0;
		int count2 = 0;
		int count3 = 0;
		int i;
		bool stop = false;
		for(i=0;i<s.size() && stop != true;i++)
		{
			if(i < ip)
			{
				if(s[i] != 'A')
					stop = true;
				else
					count1++;
			}
			else if(i>ip && i < it)
			{
				if(s[i] != 'A')
					stop = true;
				else
					count2++;
			}
			else if(i>it)
			{
				if(s[i] != 'A')
					stop = true;
				else
					count3++;
			}
		}
		if(stop)
		{
			cout << "NO" << endl;
		}
		else
		{
			if(count1 * count2 != count3)
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}
	return 0;
}

