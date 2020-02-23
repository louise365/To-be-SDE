// leetcode_1243.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//7,1,2
//6,2,2
//5,3,3
//4,4,4
class Solution {
public:
	vector<int> transformArray(vector<int>& arr) {
		if (arr.size() < 3)
			return arr;
		sort(arr.begin() + 1, arr.end() - 1);
		int minV = arr[1];
		int maxV = arr[arr.size() - 2];
		int mid = arr[(arr.size() - 1) / 2];
		double midV = (minV + maxV) / 2.0;
		int target = int((midV > mid ? 0.5 : 0) + midV);

		int count = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (i == 0 || i == arr.size() - 1)
				continue;
			arr[i] = target;
		}
		return arr;
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
