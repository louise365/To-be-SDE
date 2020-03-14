// leetcode_1143.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size();
        int size2 = text2.size();
        if (!size1 || !size2)
            return 0;
        vector<vector<int>> vt(size1+1,vector<int> (size2+1,0));
        for (int i = 1; i <= size1; ++i) {
            for (int j = 1; j <= size2; ++j) {
                if (text1[i-1] == text2[j-1])
                    vt[i][j] = vt[i - 1][j - 1] + 1;
                else
                    vt[i][j] = max(vt[i - 1][j], vt[i][j - 1]);
            }
        }
        return vt[size1][size2];
    }
};
int main()
{
    Solution s;
    s.longestCommonSubsequence("abc","def");
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
