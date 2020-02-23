// 15.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "malloc.h"
#include "memory.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int *index = (int*)malloc(sizeof(int) * numsSize);
	int *count = (int*)malloc(sizeof(int) * numsSize);
	memset(index,0,sizeof(int) * numsSize);
	memset(count,0,sizeof(int) * numsSize);
	for(int i =0;i<numsSize;i++)
		index[i] = 
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

