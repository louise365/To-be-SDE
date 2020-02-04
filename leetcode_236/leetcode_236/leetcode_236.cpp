// leetcode_236.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || root == q || root == p)
			return root;
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		if (left)
		{
			if (right)
				return  root;
			else
				return left;
		}
		else
		{
			if (left)
				return root;
			else
				return right;
		}
	}
};

class Solution1 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> _p,_q;
		find(root, p, _p);
		find(root, q, _q);
		vector<TreeNode*> *r1, *r2;
		//make r1 is shorter than r2;
		if (_p.size() < _q.size())
		{
			r1 = &_p;
			r2 = &_q;
		}
		else
		{
			r1 = &_q;
			r2 = &_p;
		}
		bool flag = false;
		TreeNode *ret = 0;
		for (int i = 0; i < (*r1).size() && !flag; i++)
			for (int j = 0; j < (*r2).size() && !flag; j++)
				if ((*r1)[i] == (*r2)[j])
				{
					flag = true;
					ret = (*r1)[i];
				}
		return ret;
	}
	bool find(TreeNode* root, TreeNode* target, vector<TreeNode*> &store)
	{
		if (root == 0)
			return false;
		if (root->val == target->val)
		{
			store.push_back(root);
			return  true;
		}
		else
		{
			if (find(root->left, target, store) ||
				find(root->right, target, store))
			{
				store.push_back(root);
				return  true;
			}
			else
				return false;
		}
	}
};

int main()
{
    return 0;
}

