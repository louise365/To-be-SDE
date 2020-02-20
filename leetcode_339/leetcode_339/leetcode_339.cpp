// leetcode_339.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
/**
* // This is the interface that allows for creating nested lists.
* // You should not implement it, or speculate about its implementation
*/
class NestedInteger {
public:
	// Constructor initializes an empty nested list.
	NestedInteger();
	// Constructor initializes a single integer.
	NestedInteger(int value);
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;
	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;
	// Set this NestedInteger to hold a single integer.
	void setInteger(int value);
	// Set this NestedInteger to hold a nested list and adds a nested integer to it.
	void add(const NestedInteger &ni);
	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};

class Solution {
public:
	int depthSum(vector<NestedInteger>& nestedList) {
		return depth(nestedList, 1);
	}
	int depth(const vector<NestedInteger> nestedList, int level)
	{
		int ret = 0;
		for (auto i = 0; i < nestedList.size(); i++)
		{
			if (nestedList[i].isInteger())
				ret += nestedList[i].getInteger() * level;
			else
				ret += depth(nestedList[i].getList(), level + 1);
		}
		return ret;
	}
};
int main()
{
	return 0;
}

