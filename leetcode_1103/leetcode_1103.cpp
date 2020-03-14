// leetcode_1103.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int count = 0;
        int& n = num_people;
        int& c = candies;
        vector<int> ret(n, 0);
        while (1)
        {
            int sum = (count + 1) * (n + 1) * n / 2 + (count + 1) * count * n * n / 2;
            if (c - sum < 0)
                break;
            ++count;
        }
        --count;
        c -= (count + 1) * (n + 1) * n / 2 + (count + 1) * count * n * n / 2;
        //if (count >= 0)
        {
            for (int i = 0; i < n; i++)
                ret[i] = (i + 1) * (count +1)+ ((count * (count + 1) ) >> 1)* n;
        }
        ++count;
        for (int i = 0; i < n; i++)
        {
            if (c - (count * n + i + 1) > 0)
            {
                ret[i] += count * n + i + 1;
                c -= count * n + i + 1;
            }
            else
            {
                ret[i] += c;
                break;
            }
        }
        return ret;
    }
};
int main()
{
    Solution s;
    s.distributeCandies(600, 4);
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
