// leetcode_1553.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution1 {
private:
    void findPath(TreeNode* root, TreeNode* target,vector<TreeNode*>& path)
    {
        if (!root)
            return;
        stack<TreeNode*> s;
        TreeNode* node = root;
        TreeNode* pre = 0;
        while(1)
        {
            while (node)
            {
                s.emplace(node);
                path.emplace_back(node);
                if (node == target)
                    return;
                node = node->left;
            }
            while (!s.empty())
            {
                node = s.top();
                
                if (node->right && node->right != pre)
                {
                    node = node->right;
                    break;
                }
                else
                {
                    pre = node;
                    s.pop();
                    path.pop_back();
                }
            }
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vtp,vtq;
        findPath(root, p, vtp);
        findPath(root, q, vtq);
        int len = min(vtq.size(), vtp.size());
        int ret = 0;
        for (int i = 0; i < len; ++i,++ret)
        {
            if (vtq[i] != vtp[i])
                break;
        }
        return (vtq.size()&&(--ret)>=0)?vtq[ret]:0;
    }
};

class Solution {
private:
    void findPath(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& pathP, vector<TreeNode*>& pathQ)
    {
        stack<TreeNode*> s;
        TreeNode* node = root, * pre = 0, * target = 0;
        while (1)
        {
            while (node)
            {
                s.emplace(node);
                pathP.emplace_back(node);
                if (target)
                {
                    if (node == target)
                        return;
                    else
                        node = node->left;
                }
                else
                {
                    if (node == p)
                    {
                        target = q;
                        //swap(pathP, pathQ);
                        pathQ = pathP;
                    }
                    else if (node == q)
                    {
                        target = p;
                        //swap(pathP, pathQ);
                        pathQ = pathP;
                    }
                    node = node->left;
                }
            }
            while (!s.empty())
            {
                node = s.top();
                if (node->right && node->right != pre)
                {
                    pre = node;
                    node = node->right;
                    break;
                }
                else
                {
                    pre = node;
                    s.pop();
                    pathP.pop_back();
                }
            }
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        findPath(root, p, q, pathP, pathQ);
        int len = min(pathP.size(), pathQ.size());
        int ret = 0;
        for (int i = 0; i < len; ++i, ++ret)
        {
            if (pathP[i] != pathQ[i])
                break;
        }
        return (pathP.size() && (--ret) >= 0) ? pathP[ret] : 0;
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    s.lowestCommonAncestor(root, root->left, root->right);
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
