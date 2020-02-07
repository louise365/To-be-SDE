// pat_b_1022.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a, b;
	long long sum;
	int d;
	cin >> a >> b >> d;
	sum = a + b;
	vector<int> out;
	while (1)
	{
		out.push_back(sum%d);
		sum /= d;
		if (sum == 0)
			break;
	}
	for (int i = out.size() - 1; i >= 0; i--)
		cout << out[i];
	cout << endl;
	//system("pause");
    return 0;
}

