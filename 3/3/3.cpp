// 3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include "memory.h"

#define ASCII_SIZE	128
int lengthOfLongestSubstring(char * s){
    if(strlen(s)    ==  0)
        return  0;

    int start=0,end=0;
    int nMax    =   1;
    int map[ASCII_SIZE];
	memset(map,-1,ASCII_SIZE*sizeof(int));
    while(end<strlen(s))
    {
        if(map[s[end]]	>=	 start)
		{
			nMax = nMax>(end-start)?nMax:(end-start);
			start = map[s[end]]+1;
			map[s[end]] = end;
			end++;
		}
		else
		{
			map[s[end]] = end;
			end++;
		}
    }

    return (end-start)>nMax?(end-start):nMax;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a = lengthOfLongestSubstring("dvdf");
	return 0;
}

