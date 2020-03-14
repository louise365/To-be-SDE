﻿// leetcode_1377.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        int pos;
        return (pos = (s1 + s2).find(s1)) != string::npos;
    }
};

class Solution1 {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        if (s1 == s2)
            return true;
        int n = s1.size();
        while (n--)
        {
            if (s1 == s2)
                return true;
            s1.push_back(s1.front());
            s1.erase(s1.begin());
        }
        return false;
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
