// leetcode_155.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <limits.h>
#include <map>
using namespace std;
struct _listNode {
	_listNode	*next;
	int val;
	_listNode(int x) : val(x), next(NULL) {}
};

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		head = 0;
	}

	void push(int x) {
		_listNode *tmp = new _listNode(x);
		if (head)
		{
			tmp->next = head;
			head = tmp;
		}
		else
			head = tmp;
		//m_nMin = findMin();
		map<int, int>::iterator iter = mp.find(head->val);
		if (iter != mp.end())
			(*iter).second++;
		else
			mp.insert(make_pair(head->val, 1));
	}

	void pop() {
		map<int, int>::iterator iter = mp.find(head->val);
		if (iter != mp.end())
		{
			(*iter).second--;
			if ((*iter).second == 0)
				mp.erase(head->val);
		}
		if (head)
			head = head->next;
		//m_nMin = findMin();
	}

	int top() {
		return head->val;
	}

	int getMin() {
		map<int, int>::iterator iter = mp.begin();
		return (*iter).first;
	}
private:
	_listNode *head;
	map<int, int> mp;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/

int main()
{
    return 0;
}

