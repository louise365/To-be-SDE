// pat_b_1042.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int map[256] = { 0 };
	string s;
	getline(cin,s);
	for (int i = 0; i < s.size(); i++)
	{
		int c = s[i];
		if (c >= 'A'&&c <= 'Z')
			c = tolower(c);
		map[c]++;
	}
	int max = 0;
	char idx = 0;
	for(int i = 'a';i<='z';i++)
		if (max < map[i])
		{
			max = map[i];
			idx = i;
		}
	cout << idx << " " << max << endl;
    return 0;
}

