// 7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math.h>
#include "LIMITS.h"

int reverse(int x){
    if(!x)  return 0;
    int stack[65] =   {0};
    int index = 0 ;
    int result = 0;
	int _x = x;
    while(x != 0)
    {
        stack[index++] = x%10;
        x /= 10;
    }
    for(int i=0;i<index;i++)
    {
        result +=   stack[i] * pow(10.0,index-i-1);
        if(result <=INT_MIN || result >= INT_MAX)
			return 0;
    }
    return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a = reverse(-2147483648);
	return 0;
}
