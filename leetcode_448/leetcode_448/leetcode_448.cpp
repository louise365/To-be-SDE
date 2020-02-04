// leetcode_448.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using namespace std;
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
	int *ret = (int*)malloc(sizeof(int)*numsSize);
	memset(ret, 0, sizeof(int)*numsSize);
	for (int i = 0; i < numsSize; i++)
		ret[nums[i]-1]++;
	int index = 0;
	for (int i = 0; i < numsSize; i++)
		if (ret[i] == 0)
			ret[index++] = i + 1;
	ret = (int*)realloc(ret, index * sizeof(int));
	*returnSize = index;
	return ret;
}
int main()
{
	int input[8] = { 4,3,2,7,8,2,3,1 };
	int size;
	int* out = findDisappearedNumbers(input,8,&size);
    return 0;
}

