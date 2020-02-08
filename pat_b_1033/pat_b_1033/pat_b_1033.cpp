// pat_b_1033.cpp : Defines the entry point for the console application.
// test case3 : there is possibility to have null as the invalid keys

#include "stdafx.h"
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	string s1, s2;
	int map[256] = { 0 };
	getline(cin,s1);
	getline(cin, s2);
	//cout << s1 << endl;
	//cout << s2 << endl;
	//cin >> s1 >> s2;
	/*for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == '+')
			for (int j = 0; j < 26; j++)
				map['A' + j] = 1;
		else if (s1[i] >= 'A' && s1[i] <= 'Z')
		{
			map[s1[i]] = 1;
			map[tolower(s1[i])] = 1;
		}
		else
			map[s1[i]] = 1;
	}
	for (int i = 0; i < s2.size(); i++)
		if (!map[s2[i]])
			cout << s2[i];
	cout << endl;
	return 0;
}*/
	unordered_set<char> st;
	unordered_set<char>::iterator it;
	for (int i = 0; i < s1.size(); i++)
	{
		//it = st.find(s1[i]);
		//if (it == st.end())
		{
			st.insert(s1[i]);
			if (s1[i] == '+')
				for (int j = 0; j < 26; j++)
					st.insert('A' + j);
			else if (s1[i] >= 'A' && s1[i] <= 'Z')
			{
				//char c = s1[i];
				//char c1 = tolower(c);
				st.insert(tolower(s1[i]));
			}
		}
	}
	for (int i = 0; i < s2.size(); i++)
	{
		it = st.find(s2[i]);
		if (
			it == st.end() 
			)
			cout << s2[i];
	}
	cout << endl;
    return 0;
}

