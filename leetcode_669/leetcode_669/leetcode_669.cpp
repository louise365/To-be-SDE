// leetcode_669.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (!root)
			return 0;
		else
		{
			if (root->val < L || root->val > R)
			{
				TreeNode *c = 0;
				if(root->left)
					c = trimBST(root->left, L, R);
				if(!c && root->right)
					c = trimBST(root->right, L, R);
				return c;
			}
			else
			{
				root->left = trimBST(root->left, L, R);
				root->right = trimBST(root->right, L, R);
				return root;
			}
		}
	}
};

int main()
{
    return 0;
}

