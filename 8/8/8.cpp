// 8.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include <math.h>
#include "limits.h"

int myAtoi(char * str){
    size_t len = strlen(str);
    if (len == 0)   return 0;
    //find first non-space
    size_t index = 0;
    bool bBegin = false;
    int index_e,index_s = 0;
    int sign = 1;
    while(index <= len)
    {
		if(str[index] == ' ' )
		{
			if(!bBegin)
			{
                index++;
				continue;
			}
            else
			{
                index_e = index;
				break;
			}
		}
		if(str[index] == '+' ||
            str[index]== '-')
		{
			if(bBegin)
			{
				index_e = index;
				break;
			}
			if(index +1 < len)
				if(str[index+1] < '0' || str[index+1] > '9')
					return 0;
				else
				{
					index++;
					continue;
				}
		}
        if(str[index] < '0' || str[index] > '9')
        {
            if(!bBegin)
                return 0;
            else
			{
                index_e = index;
				break;
			}
        }
        else
		{
			if(!bBegin)
			{
				bBegin = true;
				index_s = index;
				if(index >0)
					if(str[index-1] ==  '-')
						sign    =   -1;
			}
		}
		index++;
    }
    if(!bBegin)
        return 0;
    //handle string to integer
    double result = 0;
    for(int i=index_s;i<index_e;i++)
    {
        result += pow(10.0,index_e-i-1) * (str[i] - '0') * sign;   
        if(result <INT_MIN)
            return INT_MIN;
        if(result > INT_MAX)
            return INT_MAX;
    }
    return (int)(result);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a;
	a = myAtoi("0-1");
	a = myAtoi("2147483648");
	a = myAtoi("4193 with words");
	a = myAtoi("42");
	a = myAtoi("   -42");
	a = myAtoi("words and 987");
	a = myAtoi("-91283472332");

	return 0;
}

