// leetcode_21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1)	return l2;
		if (!l2)	return l1;
		ListNode* ret;
		if (l1->val < l2->val)
		{
			ret = l1;
			ret->next = mergeTwoLists(l1->next, l2);
		}
		else
		{
			ret = l2;
			ret->next = mergeTwoLists(l1, l2->next);
		}
		return ret;
	}
};

int main()
{
	Solution s;
	
    return 0;
}

