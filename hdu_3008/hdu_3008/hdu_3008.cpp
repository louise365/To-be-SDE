// hdu_3008.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "malloc.h"
#include "memory.h"
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	scanf("%d",&n);
	int *sum = (int*)malloc(sizeof(int) * n);
	memset(sum,0,sizeof(int) * n);
	int _n = n;
	while(n)
	{
		int m;
		scanf("%d",&m);
		int tmp;
		while(m--)
		{
			scanf("%d",&tmp);
			sum[n-1] += tmp;
		}
		n--;
	}
	while(_n)
	{
		printf("%d\n",sum[_n-1]);
		if(_n!=1)
			printf("\n");
		_n--;
	}
	free(sum);
	return 0;
}

