// PAT_BASIC_1001.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	while(cin>>n)
	{
		int count = 0;
		while(n!=1)
		{
			if(n&1)
				n = (3 * n +1)>>1;
			else
				n = n>>1;
			count++;
		}
		cout << count << endl;
	}
	return 0;
}

