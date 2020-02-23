// hdu_1.3.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "malloc.h"
#include <stdlib.h>
#include "float.h"
#include<iostream>
#include<algorithm>
#include<cstdio>

typedef struct _room
{
	double jb,cf;
	double ratio;
}room;
int cmp(const void *a, const void *b)
{
	return(((room*)a)->ratio < ((room*)b)->ratio);
}

int per(room a,room b)
{
    return a.ratio>b.ratio;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int m,n;
	room p[1001];
	while(scanf("%d %d",&m,&n) != -1)
	{
		if(m==-1 || n==-1)
			break;
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%lf %lf",&p[i].jb,&p[i].cf);
			p[i].ratio = p[i].jb / p[i].cf;
		}
		//qsort(p,n,sizeof(room),cmp);
		sort(p,p+n,per);
		double mount = 0;
		for(i=0;i<n;i++)
		{
			if(m>p[i].cf)
			{
				mount += p[i].jb;
				m -= p[i].cf;
			}
			else
			{
				mount += m * p[i].ratio;
				break;
			}
		}
		printf("%.3lf\n",mount);
	}
	
	return 0;
}

