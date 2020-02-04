// leetcode_226.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/**
* Definition for a binary tree node.
**/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root)
		{
			TreeNode *tmp = root->right;
			root->right = root->left;
			root->left = tmp;
			if(root->left)
				invertTree(root->left);
			if(root->right)
				invertTree(root->right);
		}
		return root;
	}
};

int main()
{
    return 0;
}

