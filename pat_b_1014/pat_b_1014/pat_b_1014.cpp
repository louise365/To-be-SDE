// pat_b_1014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <memory>
#include <cstring>
using namespace std;

/*
int main()
{
	unordered_map<char,int> st;
	int idx[256][2] = { 0 };
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++)
		if(idx[s1[i]][0] == 0)
			idx[s1[i]][0] = i;
	for (int i = 0; i < s2.size(); i++)
		if (idx[s2[i]][1] == 0)
			idx[s2[i]][1] = i;
	int day = 0;
	int min_s = 256,index = 0;
	for(int i = 'A';i<='Z';i++)
		if (idx[i][0] && idx[i][1])
		{
			if (min_s > max(idx[i][0], idx[i][1]))
			{
				min_s = max(idx[i][0], idx[i][1]);
				index = i;
			}
		}
	day = index - 'A' + 1;
	int _min_s = min_s;
	int time;
	min_s = 256, index = 0;
	for(int i = 0;i<256;i++)
		if (idx[i][1] > _min_s && idx[i][1] > _min_s)
		{
			if ( (i >= '0' && i <= '9' ) ||
				(i >= 'A' && i <= 'N'))
				if (min_s > max(idx[i][0], idx[i][1]))
				{
					min_s = max(idx[i][0], idx[i][1]);
					index = i;
				}
		}
	if (index >= '0' && index <= '9')
		time = index - '0';
	if (index >= 'A' && index <= 'N')
		time = index - 'A' + 10;
	cin >> s1 >> s2;
	memset(idx, 0, sizeof(int) * 256 * 2);
	for (int i = 0; i < s1.size(); i++)
		if (idx[s1[i]][0] == 0)
			idx[s1[i]][0] = i;
	for (int i = 0; i < s2.size(); i++)
		if (idx[s2[i]][1] == 0)
			idx[s2[i]][1] = i;
	min_s = 256, index = 0;
	for(int i=0;i<256;i++)
		if ((i >= 'a' && i <= 'z') ||
			(i >= 'A' && i <= 'Z'))
		{
			if (idx[i][0] && idx[i][1])
				if (min_s > max(idx[i][0], idx[i][1]))
				{
					min_s = max(idx[i][0], idx[i][1]);
					index = i;
				}
		}

	int minute = min_s;
	vector<string> days = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	//printf("%s %2d:%2d\n", days[day], time, minute);
	cout << days[day-1] << " ";
	cout.width(2);
	cout.fill('0');
	cout << time << ":";
	cout.width(2);
	cout.fill('0');
	cout << minute << endl;
    return 0;
}

*/
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int len = min(s1.size(), s2.size());
	int day = 0, hour = 0;
	int i;
	for (i = 0; i < len; i++)
	{
		if (s1[i] >= 'A' && s1[i] <= 'G' && s1[i] == s2[i])
		{
			day = s1[i] - 'A' + 1;
			break;
		}
	}
	for (i = i+1; i < len; i++)
	{
		if (s1[i] == s2[i])
		{
			if (s1[i] >= '0' && s1[i] <= '9')
			{
				hour = s1[i] - '0';
				break;
			}
			if (s1[i] >= 'A' && s1[i] <= 'N')
			{
				hour = s1[i] - 'A' + 10;
				break;
			}
		}
	}
	cin >> s1 >> s2;
	len = min(s1.size(), s2.size());
	int minute = 0;
	for (int i = 0; i < len; i++)
	{
		if (
			s1[i] == s2[i] &&
			(
			(s1[i] >= 'a' && s1[i] <= 'z') ||
			(s1[i] >= 'A' && s1[i] <= 'Z')
			)
			)
		{
			minute = i;
			break;
		}
	}
	/*vector<string> days = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	cout << days[day - 1] << " ";
	cout.width(2);
	cout.fill('0');
	cout << hour << ":";
	cout.width(2);
	cout.fill('0');
	cout << minute << endl;*/
	char week[7][4] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	printf("%s %02d:%02d", week[day - 1], hour, minute);
	return 0;
}