// PAT_BASIC_1006.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	while(cin>>n)
	{
		int i;
		for(i=0;i<n/100;i++)
		{
			cout<<"B";
		}
		for(i=0;i<n%100/10;i++)
		{
			cout<<"S";
		}
		for(i=1;i<=n%10;i++)
		{
			cout<<i;
		}
		cout<<endl;
	}
	return 0;
}

