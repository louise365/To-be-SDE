// leetcode_700.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>
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
 
class Solution1 {
private:
    TreeNode* dfs(TreeNode* node, int val) {
        if (!node)
            return 0;
        if (node->val == val)
            return node;
        else if (node->val > val) {
            if (node->left)
                return dfs(node->left, val);
            else
                return 0;
        }
        else {
            if (node->right)
                return dfs(node->right, val);
            else
                return 0;
        }
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return dfs(root, val);
    }
};


class Solution2 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
            return root;
        stack<TreeNode*> st;
        st.emplace(root);
        while (st.size()) {
            TreeNode* node = st.top();
            st.pop();
            if (node->val == val) {
                return node;
            }
            else if (node->val < val) {
                if (node->right)
                    st.emplace(node->right);
                else
                    return 0;
            }
            else {
                if (node->left)
                    st.emplace(node->left);
                else
                    return 0;
            }
        }
    }
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
            return root;
        while (root) {
            if (root->val == val)
                return root;
            else if (root->val < val)
                root = root->right;
            else
                root = root->left;
        }
        return root;
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
