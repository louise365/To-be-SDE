// hdu_3233.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct file
{
	double size;
	double sizeLeft;
	int downloaded;
	int idx;
	friend bool operator<(file a, file b)
	{
		if (a.size == b.size)
		{
			if (a.downloaded == b.downloaded)
				return a.idx>b.idx;
			else
				return a.downloaded > b.downloaded;
		}
		else
			return a.size < b.size;
	}
};

int main()
{
	int T, n, B;
	int caseCount = 0;
	while (1)
	{
		double timeCost = 0;
		cin >> T >> n >> B;
		if (!T && !n && !B)
			break;
		vector<file> fileList;
		for (int i = 0; i < T; i++)
		{
			file f;
			cin >> f.size >> f.downloaded;
			if (f.downloaded >= 100)
				continue;
			f.sizeLeft = double(100 - f.downloaded) / 100.0*f.size;
			f.idx = i;
		//	fileList.push_back(f);
			timeCost += f.sizeLeft / B;
		}
		/*sort(fileList.begin(), fileList.end());
		while (fileList.size())
		{
			int div;
			if (fileList.size() < n)
				div = fileList.size();
			else
				div = n;
			timeCost += fileList[0].sizeLeft / B * div;
			double size = fileList[0].sizeLeft;
			for (int i = 0; i < div; i++)
				fileList[i].sizeLeft -= size;
			fileList.erase(fileList.begin());
		}*/

		printf("Case %d: %.02lf\n\n",++caseCount, timeCost);
	}
    return 0;
}

