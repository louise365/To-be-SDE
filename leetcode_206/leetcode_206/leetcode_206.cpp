// leetcode_206.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *h = head, *pre = 0;
		while (h)
		{
			ListNode *t = h->next;
			h->next = pre;
			pre = h;
		}
		return pre;
	}
};

int main()
{
    return 0;
}

