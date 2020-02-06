// pat_b_1011.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int t,i = 1;
	cin >> t;
	while (i<=t)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		cout << "Case #" << i++ << ": " << ((a + b > c)?"true":"false") << endl;
	}
    return 0;
}

