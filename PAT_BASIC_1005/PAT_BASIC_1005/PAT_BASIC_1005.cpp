// PAT_BASIC_1005.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	while(cin>>n)
	{
		set<int> st;
		set<int> st1;
		int m;
		while(n--)
		{
			cin>>m;
			if(st1.find(m) == st1.end())
			{
				st1.insert(m);
				st.insert(m);
				while(m!=1)
				{
					if(m&1)
						m = 3 * m +1;
					m >>= 1;
					if(st.find(m) != st.end())
					{
						st.erase(m);
						break;
					}
					else
						st1.insert(m);
				}
			}
		}
		set<int>::reverse_iterator iter;
		for(iter = st.rbegin();iter!=st.rend();)
		{
			cout << *iter++;
			if(iter == st.rend())
				cout << endl;
			else
				cout << " ";
		}
	}
	return 0;
}

