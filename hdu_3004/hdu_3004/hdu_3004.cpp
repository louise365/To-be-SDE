// hdu_3004.cpp : �������̨Ӧ�ó������ڵ㡣
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

