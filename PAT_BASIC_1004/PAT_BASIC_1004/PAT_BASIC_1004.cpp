// PAT_BASIC_1004.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cin >> n;
	string min_name,min_num,max_name,max_num;
	int min_score = 101,max_score = -1;
	while(n--)
	{
		string name,num;
		int score;
		cin >> name >> num >> score;
		if(score > max_score)
		{
			max_name = name;
			max_num = num;
			max_score = score;
		}
		if(score < min_score)
		{
			min_name = name;
			min_num = num;
			min_score = score;
		}
	}
	cout << max_name << " " << max_num << endl;
	cout << min_name << " " << min_num << endl;
	return 0;
}

