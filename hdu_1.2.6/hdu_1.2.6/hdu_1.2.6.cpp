// hdu_1.2.6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	while(scanf("%d",&n) != -1)
	{
		while(n--)
		{
			int in;
			scanf("%d",&in);
			printf("%c",(char)in);
		}
	}
	return 0;
}

