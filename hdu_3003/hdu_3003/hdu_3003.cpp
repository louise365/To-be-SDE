// hdu_3003.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int a,b;
	while(scanf("%d %d",&a,&b))
	{
		if(a == 0 && b == 0)
			break;
		else
			printf("%d\n",a+b);
	}
	return 0;
}

