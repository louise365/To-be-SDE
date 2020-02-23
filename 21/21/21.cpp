// 21.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "malloc.h"
#include <algorithm>
struct ListNode {
      int val;
      struct ListNode *next;
 };

struct ListNode* _mergeTwoLists(struct ListNode* l1, struct ListNode* l2,
	struct ListNode* l1f, struct ListNode* l2f)
{
	if(l1->val <= l2->val)
		if(l1->next)
			l1->next = _mergeTwoLists(l1->next,l2,l1,0);
		else
			l1->next = l2;
	else
		if(l1f)
			;
		else
			l1f->next	=	l2;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l1f, l2f;
	    
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

