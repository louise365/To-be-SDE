// 4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "limits.h"
#include "math.h"

void BinarySearch(int* target,int len, int val, int& found1,int& found2, int& count)
{
	int index_s = 0,index_e = len-1,index_c = len/2;
	int min = INT_MAX, current_val;
	while(index_e != index_s)
	{
		if(abs(target[index_c] - val) < abs(target[index_s] - val))
		{
			index_s = index_c;
			index_c = (index_s+index_e)/2;
		}
		if(abs(target[index_c] - val) < abs(target[index_e] - val))
		{
			index_s = index_c;
			index_c = (index_s+index_e)/2;
		}
	}
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    double result = 0;
    // handle case of one empty array
    if(nums1Size   ==  0)
    {
        if((nums2Size&1)==0)
            result = (nums2[nums2Size/2-1] + nums2[nums2Size/2])/2;
        else
            result = nums2[nums2Size/2];
        return result;
    }
    if(nums2Size   ==  0)
    {
        if((nums1Size&1)==0)
            result = (nums1[nums1Size/2-1] + nums1[nums1Size/2])/2;
        else
            result = nums1[nums1Size/2];
        return result;
    }
    //binary search
    int nMedianA1[2],nMedianA2[2];
    int nMedianCountA1  =   0,nMedianCountA2    =   0;
    if(nums1Size && (nums1Size&1))
        nMedianA1[nMedianCountA1++] = nums1[nums1Size/2];
    if(nums1Size && ((nums1Size&1) == 0))
    {
        nMedianA1[nMedianCountA1++] = nums1[nums1Size/2-1];
        nMedianA1[nMedianCountA1++] = nums1[nums1Size/2];
    }
    if(nums2Size && (nums2Size&1))
        nMedianA2[nMedianCountA2++] = nums2[nums2Size/2];
    if(nums2Size && ((nums2Size&1) == 0))
    {
        nMedianA2[nMedianCountA2++] = nums2[nums2Size/2-1];
        nMedianA2[nMedianCountA2++] = nums2[nums2Size/2];
    }
	int found[8];
	int found_count;
    if(nMedianCountA1	==	1)
		BinarySearch(nums2,nums2Size,nMedianA1[0],found[0],found[1],found_count);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int nums1[10] = {1,2};
	int nums2[10] = {2};
	int nums1Size = 2,nums2Size = 1;

	double a = findMedianSortedArrays(nums1,nums1Size,nums2,nums2Size);
	return 0;
}

