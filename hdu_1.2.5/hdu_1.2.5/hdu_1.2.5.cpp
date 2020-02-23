// hdu_1.2.5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "math.h"


long long convert(int num,int format)
{
	long long result = 0;
	int count = 1;
	while(num)
	{
		result += (num % 10) * count;
		count *= format;
		num /= 10;
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int m;
	while(scanf("%d",&m) != -1)
	{
		long long sum = 0;
		int num;
		int format;
		while(m--)
		{
			scanf("%d(%d)",&num,&format);
			sum += convert(num,format);
		}
		printf("%ld\n",sum);
	}
	return 0;
}

