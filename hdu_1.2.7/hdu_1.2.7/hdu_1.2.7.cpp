// hdu_1.2.7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int check(int n)
{
	int sum10 = n%10+(n/10%10)+(n/100%10)+(n/1000%10);
	int sum12 = n%12+(n/12%12)+(n/144%12)+(n/1728%12);
	int sum16 = n%16+(n/16%16)+(n/256%16)+(n/4096%16);
	if(sum10 == sum12 && sum10 == sum16)
		return 1;
	else
		return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int start = 2992;
	while(start < 10000)
	{
		if(check(start))
			printf("%d\n",start);
		start++;
	}
	return 0;
}

