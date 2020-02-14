// hdu_1090.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		long long sum = 0, a;
		cin >> a >> sum;
		sum += a;
		cout << sum << endl;
	}
    return 0;
}

