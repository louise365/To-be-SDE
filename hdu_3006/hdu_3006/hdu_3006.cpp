// hdu_3006.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	while(scanf("%d",&n)!=-1)
	{
		int sum = 0;
		int tmp;
		for(int i =0;i<n;i++)
		{
			scanf("%d",&tmp);
			sum+=tmp;
		}
		printf("%d\n",sum);
	}
	return 0;
}

