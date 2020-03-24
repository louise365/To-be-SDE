// leetcode_1295.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution1 {
public:
    int findNumbers(vector<int>& nums) {
        int ret = 0;
        if (nums.empty())
            return ret;
        for (auto i : nums) {
            int count = 0;
            while (i) {
                i /= 10;
                ++count;
            }
            ret += count & 1 ? 0 : 1;
        }
        return ret;
    }
};
class Solution2 {
public:
    int findNumbers(vector<int>& nums) {
        int ret = 0;
        for (auto i : nums) {
            ret += int(log10(i)) & 1 ? 1 : 0;
        }
        return ret;
    }
};

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ret = 0;
        for (auto i : nums) {
            if ((to_string(i).size() & 1) == 0)
                ++ret;
        }
        return ret;
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
