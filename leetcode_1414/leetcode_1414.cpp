// leetcode_1414.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void merge(vector<int>& A, int m, vector<int>& B, int n) {
		
		int idx = A.size() - 1, idxa = m - 1, idxb = n - 1;
		int len = m + n;
		while (idxa >= 0 || idxb >= 0)
		{
			if (idxa >= 0 && idxb >= 0)
			{
				if (A[idxa] < B[idxb])
					A[idx--] = B[idxb--];
				else
					A[idx--] = A[idxa--];
			}
			if (idxa >= 0 && idxb < 0)
				A[idx--] = A[idxa--];
			if (idxb >= 0 && idxa < 0)
				A[idx--] = B[idxb--];
		}
	}
};
int main()
{
	std::cout << "Hello World!\n";
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
