// pat_b_1010.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vt;
	int tmp;
	while (cin >> tmp)
	{
		vt.push_back(tmp);
		if (cin.get() == '\n')
		{
			if (vt.size() && vt[vt.size()-1] == 0)
			{
				vt.erase(vt.end() - 1);
				vt.erase(vt.end() - 1);
			}
			break;
		}
	}
	for (int i = 0; i < vt.size(); i+=2)
	{
		cout << vt[i] * vt[i + 1] << " ";
		cout << vt[i + 1] - 1;
		if (i == vt.size() - 2)
			cout << endl;
		else
			cout << " ";
	}
	if (vt.size() == 0)
		cout << "0 0" << endl;
    return 0;
}

