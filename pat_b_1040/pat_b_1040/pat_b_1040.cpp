// pat_b_1040.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	const long long mode = 1000000007;
	long long ret = 0;
	char c;
	int countp = 0, counta = 0,countt = 0;
	bool flag = true;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'T')
			countt++;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'P')
			countp++;
		if (s[i] == 'T')
			countt--;
		if (s[i] == 'A')
			ret += (countp*countt) % mode;
	}
	printf("%lld\n", ret%mode);
    return 0;
}

