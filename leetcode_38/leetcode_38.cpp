﻿// leetcode_38.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i) {
            string t;
            int count = 1;
            char c = s[0];
            for (int j = 1; j < s.size(); ++j) {
                if (s[j] != c) {
                    t += to_string(count) + c;
                    c = s[j];
                    count = 1;
                }
                else
                    ++count;
            }
            if(count)
                t += to_string(count) + c;
            s = t;
        }
        return s;
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
