// pat_b_1009.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	string in;
	stack<string> st;
	while (cin >> in)
	{
		st.push(in);
		if (cin.get() == '\n')
			break;
	}
	while (st.size())
	{
		cout << st.top();
		st.pop();
		if (st.size())
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}

