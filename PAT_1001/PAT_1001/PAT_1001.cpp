// PAT_1001.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int m,n;
    while(1)
    {
		char str[20];
        if(scanf("%d %d",&m,&n) !=  -1)
        {
            int ret = m+n;
			if(ret<0)
			{
				printf("-");
				ret = -ret;
			}
			sprintf(str,"%d",ret);
			for(int i=0;str[i]!='\0';i++)
			{
				printf("%c",str[i]);
				if((strlen(str)-i-1)%3 == 0 && strlen(str)-i-1!=0)
					printf(",");
			}	
					
			printf("\n");
        }
        else
            break;
    }
    return 0;
}

