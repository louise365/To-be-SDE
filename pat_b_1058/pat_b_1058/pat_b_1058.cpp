// pat_b_1058.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Que
{
	int score;
	int numAns;
	string ans;
	int count;
	int idx;
	friend bool operator < (Que &a, Que &b)
	{
		if (a.count != b.count)
			return a.count < b.count;
		else
			return a.idx < b.idx;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	vector<Que> queList;
	for (int i = 0; i < m; i++)
	{
		Que q;
		int num;
		q.count = 0;
		q.idx = i + 1;
		cin >> q.score >> num >> q.numAns;
		for (int j = 0; j < q.numAns;)
		{
			char c;
			scanf("%c", &c);
			if (c == '\n')
				break;
			else if (c != ' ')
			{
				q.ans.push_back(c);
				j++;
			}
		}
		queList.push_back(q);
	}
	bool flag_t = true;
	int max_fail = 0;
	for (int k = 0; k < n; k++)
	{
		int score = 0;
		for (int i = 0; i < m; i++)
		{
			while (getchar() != '(');
			int num;
			scanf("%d", &num);
			bool flag = true;
			if (num < queList[i].numAns)
				flag = false;

			for (int j = 0; j < num;)
			{
				char c = getchar();
				if (c == ')')
					break;
				if (c >= 'a' && c <= 'z')
				{
					if (queList[i].ans.find(c) == string::npos)
						flag = false;
					//j++;
				}
			}
			flag_t &= flag;
			if (flag)
				score += queList[i].score;
			else
			{
				queList[i].count++;
				if (max_fail < queList[i].count)
					max_fail = queList[i].count;
			}
		}
		cout << score << endl;
	}
	if (flag_t)
		cout << "Too simple" << endl;
	else
	{
		//sort(queList.begin(), queList.end());
		int failcount = 0;
		for (int i = 0; i < m; i++)
			if (queList[i].count == max_fail)
				failcount++;
		cout << max_fail << " ";
		for (int i = 0; i < m; i++)
			if (queList[i].count == max_fail)
			{
				cout << queList[i].idx;
				failcount--;
				if (failcount)
					cout << " ";
			}
		cout << endl;
	}


	return 0;
}

