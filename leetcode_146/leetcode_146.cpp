// leetcode_146.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;
class LRUCache {
private:
    struct LinkNode
    {
        //unordered_map<int, LinkNode*>::iterator it;
        int key;
        int val;
        LinkNode* pre, * next;
        LinkNode(int v) :val(v)
        {
            pre = next = 0;
        }
    };
    unordered_map<int, LinkNode*> mp;
    int capacity;
    LinkNode* head;
    LinkNode* tail;
    void moveNodeToTail(LinkNode *p)
    {
        removeNode(p,false);
        LinkNode* pre = tail->pre;
        pre->next = p;
        p->next = tail;
        p->pre = pre;
        tail->pre = p;
    }
    void removeNode(LinkNode* p, bool bDelete = true)
    {
        if (p == tail)
            return;
        LinkNode* next = p->next;
        LinkNode* pre = p->pre;
        pre->next = next;
        next->pre = pre;
        if(bDelete)
            delete p;
    }
    void insertNode(LinkNode* p)
    {
        LinkNode* t = tail->pre;
        tail->pre = p;
        p->pre = t;
        p->next = tail;
        t->next = p;
    }
public:
    ~LRUCache()
    {
        delete head;
        delete tail;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new LinkNode(-1);
        tail = new LinkNode(-1);
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        unordered_map<int, LinkNode*>::iterator it;
        it = mp.find(key);
        if (it != mp.end())
            moveNodeToTail(it->second);

        return it == mp.end() ? -1 : it->second->val;
    }

    void put(int key, int value) {
        unordered_map<int, LinkNode*>::iterator it;
        it = mp.find(key);
        if (it != mp.end())
        {
            moveNodeToTail(it->second);
            it->second->val = value;
        }
        else
        {
            if (mp.size() == capacity)
            {
                mp.erase(head->next->key);
                removeNode(head->next);
            }
            LinkNode* p = new LinkNode(value);
            p->key = key;
            mp.insert(make_pair(key, p));
            //p->it = mp.find(key);
            insertNode(p);
        }
    }
};
int main()
{
    LRUCache LRC(2);
    LRC.put(1, 1);
    LRC.put(2, 2);
    LRC.get(1);
    LRC.put(3, 3);
    LRC.get(2);
    LRC.put(4, 4);
    LRC.get(1);
    LRC.get(3);
    LRC.get(4);
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
