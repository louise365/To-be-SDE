// leetcode_1552.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root)
			return 0;
		if (p == root)
			return p;
		if (q == root)
			return q;
		if (p->val < root->val && root->val < q->val)
			return root;
		if (q->val < root->val && root->val < p->val)
			return root;
		if (p->val < root->val && q->val < root->val)
			return lowestCommonAncestor(root->left, p, q);
		if (p->val > root->val&& q->val > root->val)
			return lowestCommonAncestor(root->right, p, q);
		return 0;
	}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root)
			return 0;
		TreeNode* node = root;
		while (node)
		{
			if ((p->val < node->val && node->val < q->val) ||
				(q->val < node->val && node->val < p->val) ||
				(p == node) ||
				(q == node))
				break;
			if (p->val < node->val && q->val < node->val)
				node = node->left;
			if (p->val > node->val&& q->val > node->val)
				node = node->right;
		}
		return node;
	}
};
int main()
{
	std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
