// leetcode_270.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
	int closestValue(TreeNode* root, double target) {
		double delta = DBL_MAX;
		int val = 0;
		vector<int> vt;
		search(root, vt);
		for (auto i : vt)
		{
			if (delta > abs(i - target))
			{
				delta = abs(i - target);
				val = i;
			}
		}
		return val;
	}
	void search(TreeNode* node, vector<int>& vt)
	{
		if (!node)
			return;
		if (node->left)
			search(node->left, vt);
		vt.push_back(node->val);
		if (node->right)
			search(node->right, vt);
	}
};

class Solution {
public:
	int closestValue(TreeNode* root, double target) {
		int ret = 0;
		double minV = DBL_MAX;
		while (root)
		{
			if (minV > abs(target - root->val))
			{
				ret = root->val;
				minV = abs(target - root->val);
			}
			root = root->val > target ? root->left : root->right;
		}
		return ret;
	}
};

int main()
{
	Solution s;
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right = new TreeNode(5);
	s.closestValue(root, 3.7);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
