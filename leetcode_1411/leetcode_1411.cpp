// leetcode_1411.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findMagicIndex(vector<int>& nums) {
		if (nums.empty() || nums.back() < 0 || nums[0] > int(nums.size() - 1))
			return -1;
		return find(nums, 0, int(nums.size() - 1));
	}
	int find(vector<int>& nums, int s, int e)
	{
		if (s > e)
			return -1;
		int ret = INT_MAX;
		int mid = s + (e - s) / 2;
		if (nums[mid] == mid && ret > mid)
			ret = mid;
		int retl = -1;
		//if (s <= mid - 1)
		retl = find(nums, s, mid - 1);
		if (retl != -1 && ret > retl)
			ret = retl;
		int retr = -1;
		if (ret == INT_MAX)// && mid + 1 <= e)
			retr = find(nums, mid + 1, e);
		if (retr != -1 && ret > retr)
			ret = retr;
		return ret == INT_MAX ? -1 : ret;
	}
};
int main()
{
	Solution s;
	vector<int> vt = { -531369933, -469065528, -430059048, -428981853, -319235969, -288076332, -286667432, -282312559, -197049680, -197022263, -174416117, -138027773, -121899023, -111631966, -107567458, -70437707, -52463072, -45519851, -38641451, -15825815, -3835472, -1525043, 22, 566842886, 593757472, 605439236, 619794079, 640069993, 657657758, 718772950, 815849552, 839357142, 936585256, 1006188278, 1042347147, 1057129320, 1062178586, 1069769438 };
	cout << s.findMagicIndex(vt) << endl;
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
