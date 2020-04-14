// simulate1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
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
private:
    int minV;
    bool flag;
    map<int, TreeNode*>mp;
    void search(TreeNode* node) {
        if (!node)
            return;
        if (mp.find(node->val) != mp.end()) {
            minV = 0;
            flag = true;
        }
        else
            mp[node->val] = node;
        if (node->left)
            search(node->left);
        if (node->right)
            search(node->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        minV = INT_MAX;
        flag = false;
        search(root);
        if (flag)
            return 0;
        map<int, TreeNode*>::iterator it = mp.begin(),pre = mp.begin();
        ++it;
        for (; it != mp.end(); ++it,++pre) {
            minV = min(minV, abs(it->first - pre->first));
        }
        return minV;
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
