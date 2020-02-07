// pat_b_1016.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string A, B;
	int DA, DB;
	cin >> A >> DA >> B >> DB;
	int countA = 0, countB = 0;
	for (int i = 0; i < A.size(); i++)
		if (DA == A[i] - '0')
			countA++;
	for (int i = 0; i < B.size(); i++)
		if (DB == B[i] - '0')
			countB++;
	long long ret = 0;
	int count = 1;
	while (countA--)
	{
		ret += count * DA;
		count *= 10;
	}
	count = 1;
	while (countB--)
	{
		ret += count *DB;
		count *= 10;
	}
	cout << ret << endl;
	//system("pause");
    return 0;
}

