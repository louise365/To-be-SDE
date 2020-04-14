// leetcode_445.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 class Solution {
 private:
     ListNode* insertNode(ListNode* p, int val) {
         ListNode* t = new ListNode(val);
         t->next = p;
         return t;
     }
 public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* ret = 0;
         vector<int> v1, v2;
         vector<int>::reverse_iterator rit1, rit2;
         while (l1) {
             v1.emplace_back(l1->val);
             l1 = l1->next;
         }
         while (l2) {
             v2.emplace_back(l2->val);
             l2 = l2->next;
         }
         rit1 = v1.rbegin();
         rit2 = v2.rbegin();
         int remain = 0;
         while (1) {
             int val1 = 0;
             int val2 = 0;
             if (rit1 != v1.rend()) {
                 val1 = *rit1;
                 ++rit1;
             }
             if (rit2 != v2.rend()) {
                 val2 = *rit2;
                 ++rit2;
             }
             remain += val1 + val2;
             ret = insertNode(ret, remain % 10);
             remain = remain / 10;
             if (rit1 == v1.rend() && rit2 == v2.rend()) {
                 if (remain)
                     ret = insertNode(ret, remain);
                 break;
             }
         }
         return ret;
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
