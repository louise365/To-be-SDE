// leetcode_108.cpp : Defines the entry point for the console application.
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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBST(nums, 0, nums.size() - 1);
	}
private:
	TreeNode* sortedArrayToBST(vector<int>& nums, int s, int e) {
		if (s > e)
			return 0;
		int m = s + (e - s) / 2;
		TreeNode *node = new TreeNode(nums[m]);
		node->left = sortedArrayToBST(nums, s, m - 1);
		node->right = sortedArrayToBST(nums, m + 1, e);
		return node;
	}
};

int main()
{
	Solution s;
	vector<int> vt;
	vt.push_back(-10);
	vt.push_back(-3);
	vt.push_back(0);
	vt.push_back(5);
	vt.push_back(9);
	s.sortedArrayToBST(vt);
    return 0;
}

