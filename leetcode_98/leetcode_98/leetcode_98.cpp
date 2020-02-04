// leetcode_98.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <limits>
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
	bool isValidBST(TreeNode* root) {
		if (root)
			return IsValid(root->left, LLONG_MIN, root->val) &
			IsValid(root->right, root->val, LLONG_MAX);
		else
			return true;
	}
	bool IsValid(TreeNode* root, int _min,int _max)
	{
		if (!root)
			return true;
		if (root->val <= _min || root->val >= _max)
			return false;

		return IsValid(root->left, _min,root->val)
			& IsValid(root->right, root->val,_max);
	}
};
int main()
{
    return 0;
}

