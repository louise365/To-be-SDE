// leetcode_244.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class WordDistance1 {
private:
    vector<string> *ref;
    unordered_map<string,int> mp;
    void insert(string& s1, string& s2, int distance)
    {
        unordered_map<string, int>::iterator it;
        string t = s1 + " " + s2;
        
        it = mp.find(t);
        if (it == mp.end())
        {
            string t2 = s2 + " " + s1;
            it = mp.find(t2);
            if (it == mp.end())
                mp.insert(make_pair(t2, distance));
            else
                it->second = min(it->second, distance);
        }
        else
            it->second = min(it->second, distance);
    }
    int find(string& s1, string& s2)
    {
        unordered_map<string, int>::iterator it;
        unordered_map<string, int>::iterator it1;
        string t = s1 + " " + s2;
        string t1 = s2 + " " + s1;
        it = mp.find(t);
        it1 = mp.find(t1);
        if (it == mp.end() && it1 == mp.end())
            return 0;
        else
            return it!=mp.end()?it->second:it1->second;
    }
public:
    WordDistance1(vector<string>& words) {
        ref = &words;
        if (ref->size()>1)
        {
            for (int i = 0; i < words.size(); ++i)
                for (int j = i; j < words.size(); ++j)
                    insert(words[i], words[j], j - i);
        }
    }

    int shortest(string word1, string word2) {
        if(ref->size() == 0)
            return 0;
        return find(word1,word2);
    }
};

class WordDistance {
private:
    unordered_map<string, vector<int>> mp;
public:
    WordDistance(vector<string>& words) {
        unordered_map<string, vector<int>>::iterator it;
        for (int i = 0;i<words.size();++i)
        {
            it = mp.find(words[i]);
            if (it == mp.end())
            {
                vector<int> vt = { i };
                mp.insert(make_pair(words[i], vt));
            }
            else
                it->second.emplace_back(i);
        }
    }

    int shortest(string word1, string word2) {
        unordered_map<string, vector<int>>::iterator it1, it2;
        it1 = mp.find(word1);
        it2 = mp.find(word2);
        if (it1 == mp.end() || it2 == mp.end())
            return 0;
        int ret = INT_MAX;
        int idx1 = 0, idx2 = 0;
        int size1 = it1->second.size();
        int size2 = it2->second.size();
        while (idx1 < size1 && idx2 < size2)
        {
            ret = min(ret, abs(it1->second[idx1] - it2->second[idx2]));
            if (it1->second[idx1] < it2->second[idx2])
                ++idx1;
            else
                ++idx2;
        }

        return ret;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
int main()
{
    vector<string>vt = { "practice", "makes", "perfect", "coding", "makes" };
    WordDistance s(vt);
    s.shortest("makes","coding");
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
