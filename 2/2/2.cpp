// 2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "malloc.h"
#include "memory.h"
/**
 * Definition for singly-linked list.
 */
 struct ListNode {
      int val;
      struct ListNode *next;
 };
 



struct ListNode returnVal;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *link = &returnVal;
    int nIncrease1   =   0, nIncrease2  =   0;
    int nCurrent    =   0;
    struct ListNode *c1 = l1, *c2 = l2;
    while(c1  ||  c2)
    {
        if(c1->next || c2->next)
        {
            link->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            memset(link->next,0,sizeof(struct ListNode));
        }
        if(c1)
        {
            nIncrease2  +=   (c1->val) % 10;
            nCurrent    +=   c1->val;
            c1  =   c1->next;
        }
        if(c2)
        {
            nIncrease2  +=   (c2->val) % 10;
            nCurrent    +=   c2->val;
            c2  =   c2->next;
        }
        link->val   =  (nIncrease1+nIncrease2)%10;
        nIncrease1  =  (nIncrease1+nCurrent)/10;
		nIncrease2	=	0;
        nCurrent    =   0;
        link = link->next;
    }
    return &returnVal;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode *c1,*c2;
	ListNode l1,l2;
	c1 = &l1, c2 = &l2;
	/*c1->val = 2;
	c1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	memset(c1->next,0,sizeof(struct ListNode));
	c1 = c1->next;
	c1->val = 4;
	c1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	memset(c1->next,0,sizeof(struct ListNode));
	c1 = c1->next;
	c1->val = 3;

	c2->val = 5;
	c2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	memset(c2->next,0,sizeof(struct ListNode));
	c2 = c2->next;
	c2->val = 6;
	c2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	memset(c2->next,0,sizeof(struct ListNode));
	c2 = c2->next;
	c2->val = 4;*/
	c1->val = 5;
	c1->next = 0;
	c2->val = 5;
	c2->next = 0;

	ListNode returnval;
	ListNode *returl = &returnval;
	returl = addTwoNumbers(&l1,&l2);
	return 0;
}

