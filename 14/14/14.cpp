// 14.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include "string.h"

char * longestCommonPrefix(char ** strs, int strsSize){
	if(!strsSize)	return "";
	size_t prefix_len = strlen(strs[0]);
	char *returnVal	=	(char*)malloc(sizeof(char) * (prefix_len+1));
	memcpy(returnVal, strs[0],prefix_len);
	returnVal[prefix_len] = '\0';
	for(int i=1;i<strsSize;i++)
	{
		if(prefix_len == 0)
			return "";
		while(prefix_len)
			if(strstr(strs[i],returnVal)!=strs[i])
				returnVal[--prefix_len] = '\0';
			else
				break;
	}
    return returnVal;
}
int _tmain(int argc, _TCHAR* argv[])
{
	char *a[3];
	a[0] = "fl";
	a[1] = "flow";
	a[2] = "floc";
	char *a4 = longestCommonPrefix(a,3);
	printf("%s",a4);
	return 0;
}

