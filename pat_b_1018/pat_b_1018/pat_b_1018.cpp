// pat_b_1018.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int cmp(char a, char b)
{
	if (a == 'C')
	{
		if (b == 'B')
			return 2;
		else if (b == 'C')
			return 0;
		else
			return 1;
	}
	else if (a == 'B')
	{
		if (b == 'B')
			return 0;
		else if (b == 'C')
			return 1;
		else
			return 2;
	}
	else//'j'
	{
		if (b == 'B')
			return 1;
		else if (b == 'C')
			return 2;
		else
			return 0;
	}
}
void insert(char a,int b,int *count)
{
	if (a == 'B')
		(*(count + 0 + b * 3))++;
	else if (a == 'C')
		(*(count + 1 + b * 3))++;
	else
		(*(count + 2 + b * 3))++;
}
char GetMax(int a, int *count)
{
	int index = 0;
	int max = 0;
	for(int i=0;i<3;i++)
		if (*(count + i + a * 3) > max)
		{
			max = *(count + i + a * 3);
			index = i;
		}
	if (index == 0)
		return 'B';
	else if (index == 1)
		return 'C';
	else
		return 'J';
}
int main()
{
	int n;
	cin >> n;
	char a, b;
	int count[6] = {0};//B,C,J
	int sum[3] = { 0 };
	while (n--)
	{
		cin >> a >> b;
		int ret = cmp(a, b);
		sum[ret]++;
		if (ret == 1)
			insert(a, 0, count);
		else if (ret == 2)
			insert(b, 1, count);
	}
	cout << sum[1] << " " << sum[0] << " " << sum[2] << endl;
	cout << sum[2] << " " << sum[0] << " " << sum[1] << endl;
	cout << GetMax(0, count) << " " << GetMax(1, count) << endl;
	system("pause");
    return 0;
}

