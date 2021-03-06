// leetcode_1405.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
		resolve(A.size(), A, B, C);
	}
	void resolve(int a, vector<int>& A, vector<int>& B, vector<int>& C) {
		if (a == 1)
		{
			C.push_back(A.back());
			A.pop_back();
			return;
		}
		else
		{
			//A[1 ~ a-1] -> B, A[0] - > C, B->C
			resolve(a - 1, A, C, B);
			C.push_back(A.back());
			A.pop_back();
			resolve(a - 1, B, A, C);
		}
	}
};

int main()
{
	Solution s;
	vector<int> A, B, C;
	A = { 2, 1, 0 }, B = {}, C = {};
	s.hanota(A, B, C);
	system("pause");
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
