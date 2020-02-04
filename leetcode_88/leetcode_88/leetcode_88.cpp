// leetcode_88.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution1 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i=0;i<n;i++)
		{
			BinaryInsert(nums1, nums2[i], m+i);
		}
	}
private:
	void BinaryInsert(vector<int>& nums1, int n,int count)
	{
		int s = 0;
		int e = count-1;
		int m = (count-1) / 2;
		int diff	=	INT_MAX;
		while (1)
		{
			if (m == 0 || m == count - 1)
				break;
			if (abs(n - nums1[m]) < diff)
				diff = abs(n - nums1[m]);
			else
				break;
			if (diff == 0)
				break;
			if (nums1[m] < n)
			{
				s = m+1;
				m = (s + e) / 2;
			}
			else
			{
				e = m-1;
				m = (s + e) / 2;
			}
		}
		nums1.insert(nums1.begin() + m, n);
		nums1.erase(nums1.end() - 1);
	}
};

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = m+n-1; i >= 0; i--)
		{
			if ((m>0 && n>0 && nums1[m - 1] > nums2[n - 1])||	n==0)
			{
				nums1[i] = nums1[m - 1];
				m--;
			}
			else
			{
				nums1[i] = nums2[n - 1];
				n--;
			}
		}
	}
};

int main()
{
	Solution s;
	vector<int> nums1, nums2;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(3);
	nums1.push_back(0);
	nums1.push_back(0);
	nums1.push_back(0);
	nums2.push_back(2);
	nums2.push_back(5);
	nums2.push_back(6);
	s.merge(nums1, 3, nums2, 3);
    return 0;
}

