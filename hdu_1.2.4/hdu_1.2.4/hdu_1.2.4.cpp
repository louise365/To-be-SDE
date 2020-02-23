// hdu_1.2.4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "memory.h"
#include "string.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char in;
	int ret = 0;
	int count = 0;
	while(in = getchar())
	{
		if(in == '#')
			return 0;
		if(in == '\n')
		{
			printf("%d\n",ret);
			ret = 0;
			count = 0;
			continue;
		}
		if(in != ' ')
		{
			ret += (count+1)*(in - 'A' + 1);
		}
		count++;
	}
	return 0;
}

