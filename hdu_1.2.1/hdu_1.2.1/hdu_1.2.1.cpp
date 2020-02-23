// hdu_1.2.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "math.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	while(scanf("%d",&n)!=-1)
	{
		if(!n)
			break;
		int sum = 0;
		int current = 0;
		int target;
		while(n--)
		{
			scanf("%d",&target);
			int diff = target - current;
			if(diff > 0)
				sum += 6 * diff	+	5;
			else if(diff < 0)
				sum += 4 * abs(diff)+5;
			else
				sum += 5;
			current = target;
		}
		printf("%d\n",sum);
	}
	return 0;
}

