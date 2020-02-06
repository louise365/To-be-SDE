// pat_b_1015.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stu {
	int code;
	int score1;
	int score2;
	int total;
	stu(int c, int s1, int s2) :code(c), score1(s1), score2(s2),total(s1+s2) {}
};

bool cmp(stu* a, stu* b)
{
	//try to simplify operations in cmp function as possible
	/*
	if (a->score1 + a->score2 == b->score1 + b->score2)
	{
		if (a->score1 == b->score1)
		{
			return a->code < b->code;
		}
		else
			return a->score1 > b->score1;
	}
	else
		return a->score1 + a->score2 > b->score1 + b->score2;
		*/
	if (a->total > b->total)
		return true;
	else if (a->total < b->total)
		return false;
	else 
	{
		if (a->score1 > b->score1)
			return true;
		else if (a->score1 < b->score1)
			return false;
		else
			return a->code < b->code;
	}
}

int main()
{
	int n, l, h;
	cin >> n >> l >> h;
	vector<stu*> class1, class2, class3, class4;
	while (n--)
	{
		int code, score1, score2;
		cin >> code >> score1 >> score2;
		stu *c = 0;
		if (score1 >= l && score2 >= l)
		{
			c = new stu(code, score1, score2);
			if (score1 >= h&&score2 >= h)
			{
				class1.push_back(c);
			}
			else if (score1 >= h && score2 < h)
			{
				class2.push_back(c);
			}
			else if (score1 >= score2 && score1 < h && score2 < h)
			{
				class3.push_back(c);
			}
			else
			{
				class4.push_back(c);
			}
		}
	}
	sort(class1.begin(), class1.end(), cmp);
	sort(class2.begin(), class2.end(), cmp);
	sort(class3.begin(), class3.end(), cmp);
	sort(class4.begin(), class4.end(), cmp);

	cout << class1.size() + class2.size() + class3.size() + class4.size() << endl;
	for (int i = 0; i < class1.size(); i++)
		cout << class1[i]->code << " " << class1[i]->score1 << " " << class1[i]->score2 << endl;
	for (int i = 0; i < class2.size(); i++)
		cout << class2[i]->code << " " << class2[i]->score1 << " " << class2[i]->score2 << endl;
	for (int i = 0; i < class3.size(); i++)
		cout << class3[i]->code << " " << class3[i]->score1 << " " << class3[i]->score2 << endl;
	for (int i = 0; i < class4.size(); i++)
		cout << class4[i]->code << " " << class4[i]->score1 << " " << class4[i]->score2 << endl;

    return 0;
}

