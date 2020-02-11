// pat_b_1054.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	double sum = 0;
	int count = 0;
	while (n--)
	{
		cin >> s;
		//check count of sign,count of dot,whether all digit
		//check dot
			//yes,check predot and afterdot
		//no,check
		int countS = 0, countD = 0;
		bool valid = true;
		for (int i = 0; i < s.size(); i++)
		{
			if (!isdigit(s[i]))
			{
				if (s[i] == '-')
				{
					if (countS == 0 && i == 0)
						countS++;
					else
					{
						valid = false; break;
					}
				}
				else if (s[i] == '.')
				{
					if (countD == 0)// && i > countS && s.size()-i<=2)
						countD++;
					else
					{
						valid = false; break;
					}
				}
				else
				{
					valid = false;
					break;
				}
			}
		}
		if (!valid)
		{
			cout << "ERROR: " << s << " is not a legal number" << endl;
			continue;
		}
		valid = true;
		int pos = s.find('.');
		if (pos != string::npos)
		{
			if (s.size() - 1 - pos > 2 ||
				pos > 4 + countS ||
				pos < countS + 1)
				valid = false;
			else
			{
				double c = atof(s.c_str());
				if(c<-1000 || c > 1000)
					valid = false;
				else
				{
					sum += atof(s.c_str());
					count++;
				}
			}
		}
		else
		{
			if (s.size() > 4 + countS)
			{
				valid = false;
			}
			else
			{
				int num = atoi(s.c_str());
				if (num < -1000 || num>1000)
					valid = false;
				else
				{
					sum += num;
					count++;
				}
			}
		}
		if (!valid)
			cout << "ERROR: " << s << " is not a legal number" << endl;
	}
	printf("The average of %d number", count);
	if (count == 0)
		printf("s is Undefined\n");
	else if(count == 1)
		printf(" is %.02lf\n", sum / count);
	else
		printf("s is %.02lf\n", sum / count);
	return 0;
}

