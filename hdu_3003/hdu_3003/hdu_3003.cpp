// hdu_3003.cpp : 定义控制台应用程序的入口点。
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

