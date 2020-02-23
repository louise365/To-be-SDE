// 35.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int searchInsert(int* nums, int numsSize, int target){
	if(target	<=	nums[0])
		return 0;
	if (target > nums[numsSize-1])
		return numsSize;
    if (target == nums[numsSize-1])
		return numsSize-1;
    int index_m = numsSize /2;
	int index_s = 0, index_e = numsSize-1;
	while(1)
	{
		if(target==nums[index_m])
			return index_m;
		else if(target>nums[index_m])
		{
            if(index_e -  index_m<= 1)
                return index_m+1;
			index_s	=	index_m;
			index_m = (index_m+index_e)/2;
		}
		else
		{
             if(index_m - index_s <= 1)
                return index_m;
			index_e	=	index_m;
			index_m = (index_m+index_s)/2;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a;
	int in[5]={2,3,5,6,9};
	a = searchInsert(in,5,7);
	a = searchInsert(in,4,2);
	a = searchInsert(in,4,7);
	a = searchInsert(in,4,0);
	return 0;
}

