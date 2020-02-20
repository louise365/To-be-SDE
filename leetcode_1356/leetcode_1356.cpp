// leetcode_1356.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
	long long gcd(long long a, long long b)
	{
		long long t;
		while (b)
		{
			t = a % b;
			a = b;
			b = t;
		}
		return a;
	}
public:
	vector<int> fraction(vector<int>& cont) {
		long long down = 1;
		long long up = cont[cont.size() - 1];
		for (int i = cont.size() - 1; i >= 0; i--)
		{
			if (cont.size() == 1)
				break;
			if (i == cont.size() - 1)
				continue;
			swap(up, down);
			up = up + down * cont[i];
		}
		long long d = gcd(up, down);
		vector<int> ret = { int(up / d),int(down / d) };
		return ret;
	}
};
int main()
{
	Solution s;
	vector<int> vt;
	//vt = { 3, 2, 0, 2 };
	vt = { 2 };
	cout << s.fraction(vt)[0]<<" "<< s.fraction(vt)[1] << endl;
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
