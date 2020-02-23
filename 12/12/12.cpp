// 12.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "memory.h"

char out[30];
char * intToRoman(int num){
    int map[7]  =   {1,5,10,50,100,500,1000};
    int mod[7];
    memset(mod,0,4*sizeof(int));
    int _num = num;
    int index=  0;
    while(num)
    {
        mod[6-index]    =   num/map[6 - index];
        num -= mod[6-index] * map[6 - index];
		index++;
    }
    int index_out = 0;
    int i;
	if(mod[0]	==	4)
		;
	else
		for(i=0;i<mod[0];i++)
			out[index_out++] = 'I';
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	intToRoman(9);
	return 0;
}

