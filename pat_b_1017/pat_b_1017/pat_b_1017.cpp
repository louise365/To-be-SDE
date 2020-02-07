// pat_b_1017.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string a;
	int b;
	cin >> a >> b;
	int idx = 0;
	string q;
	int remain = 0;
	while (1)
	{
		if (a[idx] -'0' +remain * 10 < b)
		{
			remain += (a[idx] - '0');
			if (q.size() || idx+1 == a.size())
				q.push_back('0');
		}
		else
		{
			int div = (a[idx] - '0' + remain*10) / b;
			remain = (a[idx] - '0' + remain*10) % b;
			q.push_back(div + '0');
		}
		if (++idx >= a.size())
			break;
	}
	cout << q << " " << remain << endl;
	//system("pause");
    return 0;
}

