// leetcode_1369.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>
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
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        unordered_set<int> st;
        ListNode *h = head, *h1 = head;
        while (h)
        {
            if (st.end() == st.find(h->val))
            {
                st.insert(h->val);
                if (h != head)
                {
                    h1->next = h;
                    h1 = h1->next;
                }
            }
            h = h->next;
        }
        h1->next = 0;
        return head;
    }
};
int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* h = head;
    h->next = new ListNode(2); h = h->next;
    h->next = new ListNode(3); h = h->next;
    h->next = new ListNode(3); h = h->next;
    h->next = new ListNode(2); h = h->next;
    h->next = new ListNode(1); h = h->next;
    s.removeDuplicateNodes(head);
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
