// pat_b_1047.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <unordered_map>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	unordered_map<int, int> mp;
	unordered_map<int, int>::iterator it;
	int tc, mc, score;
	for (int i = 0; i < n; i++)
	{
		scanf("%d-%d %d", &tc, &mc, &score);
		it = mp.find(tc);
		if (it == mp.end())
			mp.insert(make_pair(tc, score));
		else
			(*it).second += score;
	}
	tc = score = 0;
	for (it = mp.begin(); it != mp.end(); it++)
	{
		if ((*it).second > score)
		{
			tc = (*it).first;
			score = (*it).second;
		}
	}
	printf("%d %d\n",tc,score);
    return 0;
}

