// pat_b_1044.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	string s;
	getline(cin, s);
	n = atoi(s.c_str());
	//cin >> n;
	string mars_l[13] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
	string mars_h[13] = {"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	while (n--)
	{
		getline(cin, s);
		if (isdigit(s[0]))
		{
			int m = atoi(s.c_str());
			cout << mars_h[m / 13] << ((m / 13 && (m%13))? " " : "") << ((m%13 || m/13==0)?mars_l[m % 13]:"") << endl;
		}
		else
		{
			string m_1 = "-", m_2 = "-";
			int pos = s.find(' ');
			if (pos == string::npos)
				m_1 = s;
			else
			{
				m_1 = s.substr(0, pos);
				m_2 = s.substr(pos + 1, s.size() - 1);
				//cout << m_h << " "<<m_l << endl;
			}
			int e_l = 0, e_h = 0;
			for (int i = 0; i < 13; i++)
			{
				if (m_1 == mars_l[i] || m_2 == mars_l[i])
					e_l = i;
				if (m_1 == mars_h[i] || m_2 == mars_h[i])
					e_h = i;
			}
			cout << e_h * 13 + e_l << endl;
			//if (e_h)
				//cout << e_h << " ";
			//cout << e_l << endl;
		}
	}
    return 0;
}

