// pat_b_1023.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int count[10] = { 0 };
	int idx = -1;
	for (int i = 0; i < 10; i++)
	{
		cin >> count[i];
		if (count[i] && i != 0 && idx == -1)
		{
			idx = i;
			count[idx]--;
		}
	}
	cout << idx;
	for (int i = 0; i < 10; i++)
		if (count[i])
			for (int j = 0; j < count[i]; j++)
				cout << i;
	cout << endl;
	//system("pause");
    return 0;
}

