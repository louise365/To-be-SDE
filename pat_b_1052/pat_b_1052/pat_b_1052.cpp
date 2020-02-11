// pat_b_1052.cpp : Defines the entry point for the console application.
// shit of VS, could not store special character in string, will turn to be '?'
//also need to be careful with /\ ->//\

#include "stdafx.h"
#include <string>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
	string s[3];
	vector<string> st[3];
	for (int i = 0; i < 3;i++ )
		getline(cin, s[i]);
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < s[j].size(); )
		{
			int pos1 = s[j].find('[', i);
			int pos2 = s[j].find(']', i);
			if (pos1 != string::npos && pos2 != string::npos
				&& pos1 != s[j].size() - 1 && pos2 != 0)
			{
				st[j].push_back(s[j].substr(pos1 + 1, pos2 - 1 - pos1));
				if (pos2 + 1 < s[j].size())
					i = pos2 + 1;
				else
					i = pos2;
			}
			else
				i++;
		}
	int n;
	cin >> n;
	while (n--)
	{
		int a[5];
		cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
		string it[5];
		bool flag = true;
		for (int i = 0; i < 5; i++)
		{
			int c = i > 2 ? (4 - i) : i;
			if (a[i] >= 1 && a[i] <= st[c].size())
				it[i] = st[c][a[i]-1];
			else
				flag = false;
		}
		if (flag)
			for (int i = 0; i < 5; i++)
			{
				cout << it[i];
				if (i == 0)
					cout << "(";
				if (i == 3)
					cout << ")";
			}
		else
			cout << "Are you kidding me? @\\/@";
		cout << endl;
	}
    return 0;
}

