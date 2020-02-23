// 1016.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include "math.h"
#include "malloc.h"

bool queryString(char * S, int N){
    if(!S)  return false;
	int slen = strlen(S);
	if(N > pow(2.0, slen))	return false;
	int _N = N;
	int len = log(N*1.0) / log(2.0)+1;
	char *str = (char*)malloc((len+1) * sizeof(char));
	int count = 0;
    int tmp;
    
	while(N)
	{
        _N = N--;
        count = 0;
        while(_N)
        {
            str[count++] = (_N&1)+'0';
            _N >>= 1;
        }
        str[count]='\0';
        for(int i=0;i<count/2;i++)
        {
            tmp = str[i];
            str[i]  =   str[count-i-1];
            str[count-i-1]  =   tmp;
        }
		if(strstr(S,str)==0)
		{
			free(str);
			return false;
		}
	}
	free(str);
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	bool ret;
	ret = queryString("10010111100001110010",10);
	return 0;
}