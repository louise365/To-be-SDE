// pat_b_1032.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	unordered_map<string, int> mp;
	unordered_map<string, int>::iterator it;
	string code;
	int score;
	while (n--)
	{
		cin >> code >> score;
		it = mp.find(code);
		if (it != mp.end())
			(*it).second += score;
		else
			mp.insert(make_pair(code,score));
	}
	score = 0;
	for (it = mp.begin(); it != mp.end(); it++)
	{
		if ((*it).second > score)
		{
			score = (*it).second;
			code = (*it).first;
		}
	}
	cout << code << " " << score << endl;
    return 0;
}

