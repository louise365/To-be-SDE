// hdu_1.2.2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int gcd(int a,int b)
{
	int a1 = a/b;
	int b1 = a%b;
	if(b1==0)
		return b;
	else 
		return gcd(b,b1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n,m;
	while(scanf("%d %d",&n,&m))
	{
		if(n==-1 && m == -1)
			return 0;
		if(gcd(n,m) == 1)
			printf("YES\n");
		else
			printf("POOR Haha\n");
	}
	return 0;
}

