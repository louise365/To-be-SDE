// hdu_1.2.3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"



bool checkLeap(int n)
{
	if(n%400 == 0)	return 1;
	if(n%4 == 0 && n%100 != 0)	return 1;
	return 0;
}

int findNextLeap(int n)
{
	while(!checkLeap(n))
		n++;
	return n;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int start,n;
		scanf("%d %d",&start,&n);
		start = findNextLeap(start);
		n--;
		while(n)
		{
			start+=4;
			if(checkLeap(start))
				n--;
		}
		printf("%d\n",start);
	}
	return 0;
}

