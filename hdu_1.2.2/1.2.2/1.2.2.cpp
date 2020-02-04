// 1.2.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int m, n;
	while (scanf("%d %d", &n, &m))
	{
		if (n == -1 && m == -1)
			return 0;
		int cur = 1;
		vector<int> found;
		while (1)
		{
			if (found.size() == n)
			{
				printf("Yes\n");
				break;
			}
			if (binary_search(found.begin(), found.end(), cur))
			{
				printf("POOR Haha\n");
				break;
			}
			else
			{
				found.push_back(cur);
				cur += m;
				cur %= n;
			}
		}
	}
    return 0;
}

