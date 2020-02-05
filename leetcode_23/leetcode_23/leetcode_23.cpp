// leetcode_23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;
/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
	bool operator () (ListNode* &a, ListNode* &b)
	{
		return a->val > b->val;
	}
};

class Solution{
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue < ListNode*, vector<ListNode*>, cmp> q;
		ListNode *head	=	0, *_head	=	0;
		for (int i = 0; i < lists.size(); i++)
		{
			if (lists[i])
				q.push(lists[i]);
		}
		while (q.size())
		{
			if (!head)
				head = _head = q.top();
			else
			{
				_head->next = q.top();
				_head = _head->next;
			}
			if (q.top()->next)
				q.push(q.top()->next);
			q.pop();
		}
		return head;
	}
};

class Solution1 {
public:
	
	ListNode* mergeKLists(vector<ListNode*>& lists) {
	/*	for (int i = 0; i < lists.size(); i++)
		{
			ListNode * node = lists[i];
			while (node)
			{
				cout << node->val << "->";
				node = node->next;
			}
			cout << endl;
		}
		*/
		if (lists.size() == 0)
			return 0;
		ListNode *head = 0,*_head = 0;
		multimap<int,ListNode*> st;
		for (int i = 0; i < lists.size(); i++) {
			if(lists[i])
				st.insert(make_pair(lists[i]->val,lists[i]));
		}
		while (st.size()) {
			multimap<int, ListNode*>::iterator it = st.begin();
			if (!_head)
			{
				_head = head = (*it).second;
			}
			else
			{
				_head->next = (*it).second;
				_head = _head->next;
			}
			ListNode *node = (*it).second;
			st.erase(it);
			if (node->next)
			{
				node = node->next;
				st.insert(make_pair(node->val,node));
			}
		}
		
		return head;
	}
};
int main()
{
	vector<ListNode*> vt;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(5);
	vt.push_back(head);
	head = new ListNode(1);
	head->next = new ListNode(3);
	head->next->next = new ListNode(4);
	vt.push_back(head);
	head = new ListNode(2);
	head->next = new ListNode(6);
	vt.push_back(head);
	Solution s;
	ListNode *node;
	node = s.mergeKLists(vt);
	while (node)
	{
		cout << node->val << "->";
		node = node->next;
	}
	cout << endl;
    return 0;
}

