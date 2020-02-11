// pat_b_1057.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	//cin >> s;
	getline(cin, s);
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			sum += s[i] - 'a' + 1;
		if (s[i] >= 'A'&&s[i] <= 'Z')
			sum += s[i] - 'A' + 1;
	}
	int count[2] = { 0 };
	while (sum)
	{
		count[sum & 1]++;
		sum >>= 1;
		//	if (!sum)
			//	break;
	}
	cout << count[0] << " " << count[1] << endl;
	return 0;
}

