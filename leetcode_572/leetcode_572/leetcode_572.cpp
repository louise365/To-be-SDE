// leetcode_572.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (isTreeMatch(s, t))
			return true;
		else
		{
			if (s)
				return isSubtree(s->left, t) || isSubtree(s->right, t);
			else
				return false;
		}
	}
	bool isTreeMatch(TreeNode* s, TreeNode* t)
	{
		if (s == 0 && t == 0)
			return true;
		if ((s != 0 && t == 0)	||
			(s == 0 && t != 0))
			return false;
		if (s->val != t->val)
			return false;
		else
			return isTreeMatch(s->left, t->left)&isTreeMatch(s->right, t->right);
	}
};
int main()
{
    return 0;
}

