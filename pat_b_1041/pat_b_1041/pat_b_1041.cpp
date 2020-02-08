// pat_b_1041.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

struct stu {
	string code;
	int sit;
};

int main()
{
	int n;
	cin >> n;
	unordered_map<int, stu> mp;
	while (n--)
	{
		int sit1;
		stu s;
		cin >> s.code >> sit1 >> s.sit;
		mp.insert(make_pair(sit1, s));
	}
	int m;
	cin >> m;
	unordered_map<int, stu>::iterator it;
	while (m--)
	{
		int sit;
		cin >> sit;
		it = mp.find(sit);
		cout << (*it).second.code << " " << (*it).second.sit << endl;
	}
    return 0;
}

