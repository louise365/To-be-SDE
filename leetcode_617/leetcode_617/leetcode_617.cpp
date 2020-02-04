// leetcode_617.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == 0 && t2 == 0)
			return 0;
		else
		{
			TreeNode *c = 0;
			if (t1 && t2)
			{
				c = new TreeNode(t1->val + t2->val);
				c->left = mergeTrees(t1->left,t2->left);
				c->right = mergeTrees(t1->right, t2->right);
				return c;
			}
			else if (t1 && !t2)
			{
				return t1;
			}
			else// if (!t1 && t2)
			{
				return t2;
			}
		}
	}
};
int main()
{
    return 0;
}

