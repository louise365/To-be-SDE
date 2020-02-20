// leetcode_1528.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		int n = a.size();
		vector<int> pre(n + 1, 1);
		vector<int> after(n + 1);
		after[n] = 1;
		//pre:   1,a[0],a[0~1]...,a[0~n-2],a[0~n-1]
		//after:                 a[n-1]           ,1
		for (int i = 0; i < n; i++)
		{
			pre[i + 1] = pre[i] * a[i];
			after[n - i - 1] = after[n - i] * a[n - 1 - i];
		}
		vector<int> result;
		for (int i = 0; i < a.size(); i++)
			result.push_back(pre[i] * after[i + 1]);
		return result;
	}
};
int main()
{
	vector<int> vt;
	vt = { 1,2,3,4,5 };
	Solution s;
	s.constructArr(vt);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
