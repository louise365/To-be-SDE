// pat_b_1039.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int map[256] = { 0 };
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++)
		map[s1[i]]++;
	int count = 0;
	for (int i = 0; i < s2.size(); i++)
	{
		if (map[s2[i]])
			map[s2[i]]--;
		else
			count++;
	}
	if (count)
		cout << "No " << count << endl;
	else
		cout << "Yes " << s1.size() - s2.size() << endl;
    return 0;
}

