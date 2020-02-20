// leetcode_1496.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
class Solution1 {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		multiset<int> st;
		for (auto i : arr)
		{
			if (st.size() == k && i > (*st.rbegin()))
				continue;
			st.insert(i);
			if (st.size() == k + 1)
				st.erase((++st.rbegin()).base());
		}
		vector<int> vt;
		for (auto s : st)
			vt.push_back(s);
		return vt;
	}
};
class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		sort(arr.begin(), arr.end());
		vector<int>ret;
		for (int i = k; i < k; i++)
			ret.push_back(arr[i]);
		return ret;
	}
}
int main()
{
	Solution s;
	vector<int> vt;
	vt = { 3,2,1 };
	s.getLeastNumbers(vt, 2);
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
