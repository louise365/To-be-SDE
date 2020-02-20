// leetcode_1511.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//inorder search
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
    int kthLargest(TreeNode* root, int k) {
        int val;
        int count = 0;
        search(root, k, count, val);
        return val;
    }
    void search(TreeNode* node,int k,int &count,int &val)
    {
        if (!node || count == k)
            return;
        if (node->right)
        {
            search(node->right, k, count, val);
            if (count == k)
                return;
        }
        if (++count == k)
        {
            val = node->val;
            return;
        }
        if (node->left)
        {
            search(node->left, k, count, val);
            if (count == k)
                return;
        }
    }
};
int main()
{
    std::cout << "Hello World!\n";
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
