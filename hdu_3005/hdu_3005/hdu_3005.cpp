// hdu_3005.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int nTestCase;
	scanf("%d",&nTestCase);
	while(nTestCase--)
	{
		int nNumCount;
		scanf("%d",&nNumCount);
		int sum = 0;
		int tmp;
		while(nNumCount--)
		{
			scanf("%d",&tmp);
			sum += tmp;
		}
		printf("%d\n",sum);
	}
	return 0;
}

