// leetcode_234.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode* begin = head, * end = head, *pre = 0;
        while (end && end->next) {
            pre = begin;
            begin = begin->next;
            end = end->next->next;
        }
        ListNode* curNode = begin, *nextNode = begin->next;
        while (nextNode) {
            ListNode* tmp = nextNode->next;
            nextNode->next = curNode;
            curNode = nextNode;
            nextNode = tmp;
        }
        begin->next = 0;
        while (curNode && head) {
            if (curNode->val != head->val)
                return false;
            curNode = curNode->next;
            head = head->next;
        }
        return true;
    }
};
int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    s.isPalindrome(head);
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
