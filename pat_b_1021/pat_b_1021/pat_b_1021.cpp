// pat_b_1021.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int count[10] = { 0 };
	char c;
	while (c = cin.get())
	{
		if (c == '\n')
			break;
		else
			count[c - '0']++;
	}
	for (int i = 0; i < 10; i++)
		if (count[i])
			cout << i << ":" << count[i] << endl;
	//system("pause");
	return 0;
}

