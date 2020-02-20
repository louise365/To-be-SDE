// leetcode_243.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    unordered_map<string, vector<int>>mp;
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        unordered_map < string, vector<int>>::iterator it1, it2;
        for (int i = 0; i < words.size(); i++)
        {
            it1 = mp.find(words[i]);
            if (it1 == mp.end())
            {
                vector<int> vt = { i };
                mp.insert(make_pair(words[i], vt));
            }
            else
                (*it1).second.push_back(i);
        }
        int ret = INT_MAX;
        it1 = mp.find(word1);
        it2 = mp.find(word2);
        vector<int>::iterator it3,it4;
        for (int i = 0; i < (*it1).second.size(); i++)
        {
            for (int j = 0; j < (*it2).second.size(); j++)
            {
                if (ret > abs((*it1).second[i] - (*it2).second[j]))
                    ret = abs((*it1).second[i] - (*it2).second[j]);
            }
        }
        return ret;
    }
};

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int idx1 = -1, idx2 = -1;
        int ret = INT_MAX;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == word1)
                idx1 = i;
            if (words[i] == word2)
                idx2 = i;
            if (idx1 != -1 && idx2 != -1 && ret > abs(idx1 - idx2))
                ret = abs(idx1 - idx2);
        }
        return ret;
    }
};
int main()
{
    vector<string> vt = {};
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
