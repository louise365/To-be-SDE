// leetcode_32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

struct Node {
	int s, e;
	Node() :s(-1), e(-1) {}
	Node(int a, int b) :s(a), e(b) {}
	friend bool operator< (const Node &a, const Node &b)
	{
		return (a.e - a.s) > (b.e - b.s);
	}
};

class Solution_stack1 {
public:
	int longestValidParentheses(string s) {
		int ret = 0, current = 0;
		vector<Node*> nodeList;
		stack<int> st;
		for (int i = 0; i < s.size();i++)
		{
			if (s[i] == '(')
				st.push(i);
			else
			{
				if (!st.empty())
				{
					Node *node = new Node(st.top(), i);
					insertNode(nodeList, node);
					st.pop();
				}
			}
			/*Node *node = findNode(s,i);
			if (node)
			{
				insertNode(nodeList, node);
				i = node->e;
			}
			else
				i++;*/

		}
		//sort(nodeList.begin(), nodeList.end());

		return longestValid(nodeList);
	}
	void insertNode(vector<Node*> &nodeList, Node* node)
	{
		if (!node)	return;
		if (nodeList.size() == 0)
		{
			nodeList.push_back(node);
			return;
		}
		
		for (int i = 0; i < nodeList.size(); i++)
		{
			if (node->e + 1 < nodeList[i]->s	||
				node->s > nodeList[i]->e + 1)
				continue;
			else
			{
				nodeList[i]->s = min(nodeList[i]->s, node->s);
				nodeList[i]->e = max(nodeList[i]->e, node->e);
				return;
			}
		}
		nodeList.push_back(node);
	}
	Node *findNode(string s, int idx)
	{
		Node *node = 0;
		int count = 0;
		int flag = false;
		while (1)
		{
			if (idx - count < 0 || idx + count + 1 >= s.size())
				break;
			else
			{
				if (s[idx - count] == '(' && s[idx + count + 1] == ')')
				{
					flag = true;
					count++;
				}
				else
					break;
			}
		}
		if (flag)
			node = new Node(idx-count+1,idx+count);
		return node;
	}
	int longestValid(vector<Node*> &nodeList)
	{
		int ret = 0;
		//if (nodeList.size())
			//return nodeList[0]->e - nodeList[0]->s + 1;
		for (int i = 0; i < nodeList.size(); i++)
			if (ret < nodeList[i]->e - nodeList[i]->s + 1)
				ret = nodeList[i]->e - nodeList[i]->s + 1;
		return ret;
	}
};

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> st;
		int ret = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				st.push(i);
			else
			{
				if (st.size())
				{
					ret = max(i - st.top() + 1, ret);
					st.pop();
				}
				else
					while (!st.empty())
						st.pop();
			}
		}
		return ret;
	}
};

int main()
{
	Solution s;
	string in = "(()";
//	cout << s.longestValidParentheses(in) << endl;
	in = ")()())";
	//cout << s.longestValidParentheses(in) << endl;
	in = "()(())";
	//cout << s.longestValidParentheses(in) << endl;
	in = ")(())))(())())";
	cout << s.longestValidParentheses(in) << endl;
    return 0;
}

