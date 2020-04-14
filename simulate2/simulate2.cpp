// simulate2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//d[i] = max(a[i] + d[i-2], d[i-1])
class Solution {
private:
    int myrob(vector<int>& nums,int start, int end) {
            int premax = 0;
            int curmax = 0;
            for (int i = start; i <= end; ++i) {
                int t = curmax;
                curmax = max(nums[i] + premax, curmax);
                premax = t;
            }
            return curmax;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        return max(myrob(nums, 0, nums.size() - 2), myrob(nums, 1, nums.size() - 1));
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
