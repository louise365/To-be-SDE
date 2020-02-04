// leetcode_202.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <set>
#include <iostream>
using namespace std;

class Solution1 {
public:
	bool isHappy(int n) {
		set<int> st;
		while (n != 1)
		{
			if (st.find(n) != st.end())
				return false;
			else
				st.insert(n);
			int t = n;
			int sum = 0;
			while (t)
			{
				sum += (t % 10)*(t % 10);
				t /= 10;
			}
			n = sum;
		}
		return true;
	}
};

class Solution {
public:
	bool isHappy(int n) {
		int slow = n;
		int fast = n;
		bool first = true;
		while (1)
		{
			if (slow == 1 ||
				fast == 1)
				return true;
			if (slow == fast	&&	first!=true)
				return false;
			slow = CalculateNext(slow);
			fast = CalculateNext(CalculateNext(fast));
			if (first)
				first = false;
		}
	}
private:
	int CalculateNext(int n)
	{
		int sum = 0;
		while (n)
		{
			sum += (n%10)*(n%10);
			n /= 10;
		}
		return sum;
	}
};

int main()
{
	Solution s;
	cout << s.isHappy(2) << endl;
	cout << s.isHappy(19) << endl;
    return 0;
}

