// pku_2823.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#if SOLUTION1
struct node {
	int min;
	int max;
};

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> vt;
	map<int,int> mp;
	map<int, int>::iterator it;
	vector<node> nodeList;
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		vt.push_back(t);
		if (i <= k-1)
		{
			it = mp.find(t);
			if (it == mp.end())
				mp.insert(make_pair(t, 1));
			else
				(*it).second++;
		}
		if (i == k - 1)
		{
			node n;
			n.min = (*mp.begin()).first;
			n.max = (*mp.rbegin()).first;
			nodeList.push_back(n);
		}
		if(i>k-1)
		{
			it = mp.find(vt[i - k]);
			if (--(*it).second == 0)
				mp.erase(it);
			it = mp.find(t);
			if (it == mp.end())
				mp.insert(make_pair(t, 1));
			else
				(*it).second++;
			node n;
			n.min = (*mp.begin()).first;
			n.max = (*mp.rbegin()).first;
			nodeList.push_back(n);
		}
	}
	for (int i = 0; i < nodeList.size(); i++)
		printf("%d%c", nodeList[i].min, i == nodeList.size() - 1 ? '\n' : ' ');
	for (int i = 0; i < nodeList.size(); i++)
		printf("%d%c", nodeList[i].max, i == nodeList.size() - 1 ? '\n' : ' ');

    return 0;
}
#endif

struct node
{
	int val;
	int idx;
};

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> ansList;
	deque<node> qMin, qMax;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		node t;
		t.idx = i;
		scanf("%d", &t.val);
		
		while (qMin.size() && qMin.front().idx <= i - k)
			qMin.pop_front();
		while (qMin.size() && qMin.back().val >= t.val)
			qMin.pop_back();
		qMin.push_back(t);
		
		while (qMax.size() && qMax.front().idx <= i - k)
			qMax.pop_front();
		while (qMax.size() && qMax.back().val <= t.val)
			qMax.pop_back();
		qMax.push_back(t);

		if (i>=k-1)
		{
			printf("%d%c", qMin.front().val, i == n - 1 ? '\n' : ' ');
			ansList.push_back(qMax.front().val);
		}
	}
	for(int i = 0;i<ansList.size();i++)
		printf("%d%c", ansList[i], i == ansList.size()-1 ? '\n' : ' ');
	return 0;
}


