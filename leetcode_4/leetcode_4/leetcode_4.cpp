// leetcode_4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if(nums1.size() < nums2.size())
			return findMedianSortedArrays(nums2,nums1);
		vector<int>::iterator iter;
		for(iter = nums1.begin();iter!=nums1.end();iter++)
			nums2.push_back(*iter);
		sort(nums2.begin(),nums2.end());
		int k = nums2.size();
		if(k&1)
			return nums2[k/2] * 1.0f;
		else
			return (nums2[k/2-1] + nums2[k/2])/2.0;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		//nums1 is shorter than nums2
		if(nums1.size() > nums2.size())
			return findMedianSortedArrays(nums2,nums1);
		int m = nums1.size();
		int n = nums2.size();
		int iMin = 0;
		int iMax = m;
		int i,j;
		int len = (m+n+1)/2;
		while(1)
		{
			i = (iMin+iMax)/2;
			j = len -i;
			if(i!=m && j!=0 && nums2[j-1] > nums1[i])
			{
				iMin = i+1;
			}
			else if(i!=0 && j!=n && nums1[i-1] > nums2[j])
			{
				iMax = i-1;
			}
			else
			{
				int maxLeft=  0;
				if(i==0)
					maxLeft = nums2[j-1];
				else if(j==0)
					maxLeft = nums1[i-1];
				else
					maxLeft = max(nums1[i-1],nums2[j-1]);
				if((nums1.size() + nums2.size())&1)
					return maxLeft;
				int minRight = 0;
				if(i==m)
					minRight = nums2[j];
				else if(j==n)
					minRight = nums1[i];
				else 
					minRight = min(nums1[i],nums2[j]);
				
				return (minRight+maxLeft)/2.0;
			}
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector<int> nums1, nums2;
	nums1.push_back(1);
	nums1.push_back(3);
	nums2.push_back(2);
	double ret = s.findMedianSortedArrays(nums1,nums2);
	cout << ret << endl;
	nums1.clear();
	nums2.clear();
	nums1.push_back(1);
	nums1.push_back(2);
	nums2.push_back(3);
	nums2.push_back(4);
	ret = s.findMedianSortedArrays(nums1,nums2);
	cout << ret << endl;
	return 0;
}

