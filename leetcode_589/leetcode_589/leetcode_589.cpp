// leetcode_589.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using namespace std;
/*
// Definition for a Node.
*/
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
	val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	vector<int> preorder(Node* root) {
		vector<int> ret;
		vector<Node*> stack;
		vector<Node*>::reverse_iterator riter;
		stack.push_back(root);
		while (stack.size() != 0)
		{
			riter = stack.rbegin();
			if (riter==stack.rend() || (*riter) == 0)
				break;
			ret.push_back((*riter)->val);
			Node *current = (*riter);
			stack.pop_back();
			if (current->children.size() != 0)
			{
				vector<Node*>::reverse_iterator riter1;
				for (riter1 = current->children.rbegin(); riter1 != current->children.rend(); riter1++)
					stack.push_back(*riter1);
			}
		}
		return ret;
	}
};

int main()
{
	//1,nil,3,2,4,nil,5,6
	Node node[6];
	for (int i = 0; i < 6; i++)
		node[i] = i + 1;
	node[0].children.push_back(&node[2]);//1
	node[0].children.push_back(&node[1]);
	node[0].children.push_back(&node[3]);
	node[2].children.push_back(&node[4]);
	node[2].children.push_back(&node[5]);
	Solution s;
	s.preorder(node);
    return 0;
}

