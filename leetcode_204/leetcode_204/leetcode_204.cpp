// leetcode_204.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		int ret = 0;
		for (int i = 2; i < n; i++)
			ret += isPrime(i);
		return ret;
	}
private:
	bool isPrime(int n) {
		if (n == 2 || n == 3)
			return true;
		int s = (int)(sqrt(n));
		for (int i = 2; i <= s; i++)
			if (n%i == 0)
				return false;
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.countPrimes(20) << endl;
    return 0;
}

