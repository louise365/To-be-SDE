// pat_b_1038.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int map[101] = { 0 };
	while (n--)
	{
		int score;
		cin >> score;
		map[score]++;
	}
	int k;
	cin >> k;
	for(int i = 0;i<k;i++)
	{
		int score;
		cin >> score;
		cout << map[score];
		if (i != k - 1)
			cout << " ";
		else
			cout << endl;
	}
    return 0;
}

