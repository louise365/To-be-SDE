// pat_b_1019.cpp : Defines the entry point for the console application.
//
//comments:
//cout/string is TLE in half of the test cases, have to use stdio functions to output and array to handle with data instead of vector/string
#include "stdafx.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
using namespace std;

bool cmp(char a, char b)
{
	return a < b;
}
bool cmp1(char a, char b)
{
	return a > b;
}

bool cmp2(int a, int b)
{
	return a > b;
}
int main()
{
	int tmp;
	int in[4];
	cin >> tmp;
	in[0] = tmp / 1000;
	in[1] = tmp % 1000 / 100;
	in[2] = tmp % 100 / 10;
	in[3] = tmp % 10;
	//set<string> st;
//	FILE* fp;
	//fopen_s(&fp, "PAT_B_1019_1.txt", "w");
	//for (int i = 0; i < 10000; i++)
	{
		/*stringstream ss;
		ss.width(4);
		ss.fill('0');
		ss << i;
		in = ss.str();*/
	//	fprintf(fp, "%d\n", i);
		//string a = in, b = in;
		while (1)
		{
			//sort(a.begin(), a.end(), cmp1);
			sort(in, in + 4, cmp2);
			//for (int i = 0; i < 4; i++)
				//b[i] = a[3 - i];
			printf("%d%d%d%d - %d%d%d%d = ", in[0], in[1], in[2], in[3], in[3], in[2], in[1], in[0]);
			tmp = (in[0] - in[3]) * 1000 + (in[1] - in[2]) * 100 + (in[2] - in[1]) * 10 + (in[3] - in[0]);
			in[0] = tmp / 1000;
			in[1] = tmp % 1000 / 100;
			in[2] = tmp % 100 / 10;
			in[3] = tmp % 10;
			printf("%04d\n", tmp);
			/*sort(b.begin(), b.end(), cmp);
			int remain = 0;
			for (int i = in.size() - 1; i >= 0; i--)
			{
				if (a[i] + remain < b[i])
				{
					in[i] = 10 + a[i] - b[i] + '0' + remain;
					remain = -1;
				}
				else
				{
					in[i] = a[i] - b[i] + '0' + remain;
					remain = 0;
				}
			}*/

		//	cout << a << " - " << b << " = " << in << endl;
			//printf("%s - %s = %s\n", a.c_str(), b.c_str(), in.c_str());
		//	if (in == "0000" || in == "6174")
			if(tmp == 0 || tmp == 6174)
				break;
			//fprintf_s(fp, "%s - %s = %s\n", a.c_str(), b.c_str(), in.c_str());
		}
	}
	//fclose(fp);
	
	//system("pause");
    return 0;
}

