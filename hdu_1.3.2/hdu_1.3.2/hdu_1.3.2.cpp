// hdu_1.3.2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <search.h>

typedef struct _path
{
	int a,b;
	int len;
	int flag; 
}path;
path p[200];
int cmp(const void *a, const void *b)
{
	return ((path*)a)->len < ((path*)b)->len;
}

void swap(int &a,int &b)
{
	int t = a;
	a = b;
	b = t;
}

int conflict(path a, path b)
{
	return a.b >= b.a;
}

void find(int index,int count)
{
	//每次寻找剩余长度最小的配对，递归
	;
	find(p[index].a)
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n,i;
	
	while(scanf("%d",&n)!=-1)
	{
		while(n--)
		{
			int t;
			scanf("%d",&t);
			for(i=0;i<t;i++)
			{
				scanf("%d %d",&p[i].a,&p[i].b);
				if(p[i].a > p[i].b)
					swap(p[i].a,p[i].b);
				p[i].len = p[i].b - p[i].a;
				p[i].flag = 1;
			}
			qsort(p,t,sizeof(_path),cmp);
			int count = 0;
			int _t = t;
			while(_t)
			{
				for(i=0;i<t;i++)
				{
					if(p[i].flag)
					{
						find(i,_t);
						count++;
					}
				}
			}
			printf("%d\n",count*10);
		}
	}
	return 0;
}

