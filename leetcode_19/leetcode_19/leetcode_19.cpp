// leetcode_19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		vector<ListNode*> vt;
		ListNode* node = head;
		while (node)
		{
			vt.push_back(node);
			node = node->next;
		}
		if (vt.size() == n)
		{
			if (vt.size() > 1)
				return vt[1];
			else
				return 0;
		}
		else if (vt.size() < n)
			return head;
		else if (n == 1)
		{
			if (vt.size() > 1)
				vt[vt.size() - 2]->next = 0;
			else
				return 0;
		}
		else
			vt[vt.size() - n - 1]->next = vt[vt.size() - n + 1];
		return head;
	}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *n1, *n2, h(0);
		n1 = n2 = &h;
		h.next = head;
		while (n--)
		{
			n2 = n2->next;
		}
		while (n2)
		{
			if (n2->next == 0)
				break;
			n1 = n1->next;
			n2 = n2->next;
		}
		n1->next = n1->next ? n1->next->next : 0;
		return  h.next;
	}
};

int main()
{
	Solution s;
	
    return 0;
}

