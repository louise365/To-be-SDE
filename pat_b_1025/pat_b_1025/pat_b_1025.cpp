// pat_b_1025.cpp : Defines the entry point for the console application.
//be carefule with invalid input, and make sure the next of end of the link is -1

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct node {
	string add;
	int val;
	string next;
};
int main()
{
	string adds;
	int n, k;
	cin >> adds >> n >> k;
	vector<node> nodeList;
	while (n--)
	{
		node nd;
		cin >> nd.add >> nd.val >> nd.next;
		nodeList.push_back(nd);
	}
	//sort(nodeList.begin(), nodeList.end());
	//sort
	string head = adds;
	node tmp;
	int idx = -1;
	for (int i = 0; i < nodeList.size(); i++)
	{
		int j;
		for (j = i; j < nodeList.size(); j++)
		{
			if (nodeList[j].add == head)
			{
				tmp = nodeList[i];
				nodeList[i] = nodeList[j];
				nodeList[j] = tmp;
				head = nodeList[i].next;
				break;
			}
		}
		if (j == nodeList.size())
		{
			idx = i;
			break;
		}
	}
	if (idx != -1)
	{
		vector<node>::iterator it = nodeList.begin();
		int count = 0;
		while (count++ < idx)
			it++;
		nodeList.erase(it,nodeList.end());
	}
	for (int i = 0; i < nodeList.size();)
	{
		if (i + k - 1 < nodeList.size())
		{
			for (int j = 0; j < (k)/2; j++)
			{
				//i+k-1
				int base = i;
				tmp = nodeList[j+base];
				nodeList[j+base] = nodeList[k-j-1+base];
				nodeList[k - j - 1 + base] = tmp;
			}
			i += k;
		}
		else
			break;
	}
	for (int i = 0; i < nodeList.size()-1; i++)
	{
		nodeList[i].next = nodeList[i + 1].add;
	}
	for (int i = 0; i < nodeList.size(); i++)
		cout << nodeList[i].add << " " << nodeList[i].val << " " << (i == nodeList.size()-1?"-1":nodeList[i].next) << endl;
	//system("pause");
    return 0;
}

