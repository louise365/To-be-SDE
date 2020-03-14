// leetcode_1463.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
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
    TreeNode* convertBiNode(TreeNode* root) {
        TreeNode* mr = 0;
        return resolve(root, mr);
    }
    TreeNode* resolve(TreeNode* node,TreeNode *&mr) {
        if (!node)
            return 0;
        if (!node->left && !node->right)
        {
            mr = node;
            return node;
        }
        TreeNode* left = 0, * right = 0, *ret = 0;
        TreeNode* mrl = 0, * mrr = 0;
        if (node->left)
            left = resolve(node->left, mrl);
        if (left)
        {
            ret = left;
            if (mrl)
                mrl->right = node;
            else
                ret->right = node;
            mr = node;
        }
        if(node->right)
            right = resolve(node->right, mrr);
        if (right)
        {
            if (!left)
                ret = node;
            node->right = right;
            if (mrr)
                mr = mrr;
        }
        node->left = 0;
        return ret;
    }
};
int main()
{
    Solution s;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->left->left = new TreeNode(0);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    s.convertBiNode(root);
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
