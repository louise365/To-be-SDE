// leetcode_695.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
private:
	int maxV;
	int row;
	int col;
	void DFS(vector<vector<bool>>& flag, vector<vector<int>>& grid, int x, int y, int& cnt)
	{
		if (!grid[y][x] || flag[y][x])
			return;
		flag[y][x] = true;
		if (x - 1 >= 0 && grid[y][x - 1] && !flag[y][x - 1])
			DFS(flag, grid, x - 1, y, ++cnt);
		if (x + 1 < col && grid[y][x + 1] && !flag[y][x + 1])
			DFS(flag, grid, x + 1, y, ++cnt);
		if (y - 1 >= 0 && grid[y - 1][x] && !flag[y - 1][x])
			DFS(flag, grid, x, y - 1, ++cnt);
		if (y + 1 < row && grid[y + 1][x] && !flag[y + 1][x])
			DFS(flag, grid, x, y + 1, ++cnt);
		maxV = max(maxV, cnt);
	}
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty())
			return 0;
		row = grid.size();
		col = grid[0].size();
		maxV = 0;
		vector<vector<bool>> flag(row, vector<bool>(col, false));
		int cnt;
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				if (grid[i][j] && !flag[i][j])
				{
					cnt = 1;
					DFS(flag, grid, j, i, cnt);
				}
		return maxV;
	}
};
int main()
{
	std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
