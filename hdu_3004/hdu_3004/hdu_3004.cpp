// hdu_3004.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	while(scanf("%d",&n) && n)
	{
		int sum = 0;
		int tmp;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&tmp);
			sum += tmp;
		}
		printf("%d\n",sum);
	}
	return 0;
}

