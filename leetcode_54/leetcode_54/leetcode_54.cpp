// leetcode_54.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;
		if (matrix.size() == 0)
			return ret;
		int row = matrix.size();
		int col = matrix[0].size();
		int count = row * col;
		unsigned int i_row = 0, i_col = 0;
		unsigned int c_l, c_r, c_t, c_b;
		c_l = c_t = 0;
		c_r = col - 1;
		c_b = row - 1;
		while (count>0)
		{
			while (c_l <= i_col && i_col <= c_r && count)
			{
				ret.push_back(matrix[i_row][i_col++]);
				count--;
			}
			c_t++; i_row = c_t; i_col--;
			while (c_t <= i_row && i_row <= c_b && count)
			{
				ret.push_back(matrix[i_row++][i_col]);
				count--;
			}
			c_r--; i_col = c_r; i_row--;
			while (c_l <= i_col && i_col <= c_r && count)
			{
				ret.push_back(matrix[i_row][i_col--]);
				count--;
			}
			c_b--; i_row = c_b; i_col++;
			while (c_t <= i_row && i_row <= c_b && count)
			{
				ret.push_back(matrix[i_row--][i_col]);
				count--;
			}
			c_l++; i_col = c_l; i_row++;
		}
		return  ret;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> vt;
	vector<int> v0 = { 1,2,3,4 };
	vector<int> v1 = { 5,6,7,8 };
	vector<int> v2 = { 9,10,11,12 };
	vt.push_back(v0);
	vt.push_back(v1);
	vt.push_back(v2);
	vector<int> ret = s.spiralOrder(vt);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
	cout << endl;
    return 0;
}

