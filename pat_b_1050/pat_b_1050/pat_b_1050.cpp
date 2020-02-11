// pat_b_1050.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> vt;
	for (int i = 0; i < N; i++)
	{
		int t;
		scanf("%d", &t);
		vt.push_back(t);
	}
	sort(vt.begin(), vt.end());
	int m, n;
	int s = sqrt(N);
	int min = 10001;
	for (int i = 1; i <= s; i++)
	{
		if (N%i == 0)
		{
			n = i > N / i ? N / i : i;
			m = N / n;
			if (m - n < min)
				min = m - n;
		}
	}
	int l = 0, r = n - 1, t = 0, b = m - 1;
	int *out = new int[m*n];
	while (N)
	{
		for (int i = l; i <= r && N; i++, N--)
			out[t*n + i] = vt[N - 1];
		t++;
		for (int i = t; i <= b && N; i++, N--)
			out[i*n + r] = vt[N - 1];
		r--;
		for (int i = r; i >= l && N; i--, N--)
			out[b*n + i] = vt[N - 1];
		b--;
		for (int i = b; i >= t && N; i--, N--)
			out[i*n + l] = vt[N - 1];
		l++;
	}
	for (int i = 0; i < vt.size(); i++)
		printf("%d%c", out[i], ((i + 1) % n == 0) ? '\n' : ' ');
	delete[] out;
	return 0;
}

