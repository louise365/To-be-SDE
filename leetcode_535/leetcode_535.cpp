// leetcode_535.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unsigned long long count;
    unordered_map<unsigned long long,string>mp;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        mp.emplace(make_pair(count, longUrl.substr(longUrl.find(":")+3)));
        return longUrl.substr(0, longUrl.find(":")) + "://" + to_string(count++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortUrl.substr(0, shortUrl.find(":")) + +"://" + mp[stol(shortUrl.substr(shortUrl.find(":")+3))];
    }
};

int main()
{
    Solution s;
    string t1 = s.encode("https://leetcode.com/problems/design-tinyurl");
    string t2 = s.decode(t1);
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
