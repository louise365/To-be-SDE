// poj1321.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "malloc.h"
#include "memory.h"
#include <list>

int _tmain(int argc, _TCHAR* argv[])
{
	int n,k;
	while(scanf("%d %d",&n,&k))
	{
		if(n == -1 && k == -1)
			return 0;
		char *input = (char*)malloc(sizeof(char) * n);
		bool *point = (bool*)malloc(sizeof(bool) * n * n * 2);
		std::list<int,int>_point;
		memset(point,-1, sizeof(bool) * n * n * 2);
		for(int i=0;i<n;i++)
		{
			scanf("%s\n",input);
			for(int j =0;j<n;j++)
				if(input[j]	==	'#')
				{
					_point.push_back(i,j);
					point[2*i*n+j*2 + 0] = i;
					point[2*i*n+j*2 + 1] = j;
				}
		}
		//search for solution
		int count = 0;
		//output
		printf("%d\n",count);
		free(input);
		free(point);
	}
	return 0;
}

