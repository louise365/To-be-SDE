// pat_b_1029.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//unordered_set/unordered_map could only be useded as hashtable, the sequence of insert will be lost after the key is inserted into container
/*
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
	transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
	int map[256] = { 0 };
	for (int i = 0; i < s2.size(); i++)
		map[s2[i]] = 1;
	for (int i = 0; i < s1.size(); i++)
		if (map[s1[i]] == 0)
		{
			cout << s1[i];
			map[s1[i]] = 1;
		}
	cout << endl;
    return 0;
}
*/
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int map[256] = { -1 };
	//unordered_set<char>st;
	vector<char>st;
	string s1, s2;
	cin >> s1 >> s2;
	transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
	transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
	//unordered_set<char>::iterator it;
	vector<char>::iterator it;
	/*for (int i = 0; i < s2.size(); i++)
	{
		it = st.find(s2[i]);
		if (it == st.end())
			st.insert(s2[i]);
	}
	for (int i = 0; i < s1.size(); i++)
	{
		it = st.find(s1[i]);
		if (it == st.end())
		{
			cout << s1[i];
			st.insert(s1[i]);
		}
	}*/
	/*for (int i = 0; i < s1.size(); i++)
	{
		it = st.find(s1[i]);
		if (it == st.end())
			st.insert(s1[i]);
	}

	for (int i = 0; i < s2.size(); i++)
	{
		it = st.find(s2[i]);
		if (it != st.end())
			st.erase(it);
	}*/
	for (int i = 0; i < s1.size(); i++)
	{
		for (it = st.begin(); it != st.end(); it++)
			if (*it == s1[i])
				break;
		if (it == st.end())
			st.push_back(s1[i]);
	}
	for (int i = 0; i < s2.size(); i++)
	{
		for (it = st.begin(); it != st.end(); it++)
			if (*it == s2[i])
			{
				st.erase(it);
				break;
			}
	}

	for (it = st.begin(); it != st.end(); it++)
		cout << (*it);
	cout << endl;
	return 0;
}