// leetcode_141.cpp : Defines the entry point for the console application.
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
	bool hasCycle(ListNode *head) {
		ListNode *slow	=	head, *fast	=	head;
		while (1)
		{
			if (slow == 0 ||
				fast == 0 || 
				slow->next == 0 ||
				fast->next->next == 0 )
				return false;
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				return true;
		}
	}
};

int main()
{
	Solution s;
	
    return 0;
}

