// leetcode852.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
class Solution1 {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		int index = -1;
		for (int i = 1; i < A.size() - 1; i++)
			if (A[i] > A[i - 1] && A[i] > A[i + 1])
			{
				index = i;
				break;
			}
		return index;
	}
};
class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		int s = 1;
		int e = A.size() - 1;
		int mid = s + (e - s) / 2;
		while (s <= e)
		{
			if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
				break;
			if (A[mid] < A[mid - 1])
				e = mid - 1;
			else if (A[mid] < A[mid + 1])
				s = mid + 1;
			mid = s + (e - s) / 2;
		}
		return mid;
	}
};

int main()
{
	Solution s;
	vector<int> vt = { 0,1,0 };
	vector<int> vt1 = { 0,2,1,0 };
	cout << s.peakIndexInMountainArray(vt) << endl;
	cout << s.peakIndexInMountainArray(vt1) << endl;
    return 0;
}

