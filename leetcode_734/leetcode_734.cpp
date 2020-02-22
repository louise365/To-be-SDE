// leetcode_734.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size())
            return false;
        unordered_set<string> st;
        for (auto c : pairs)
        {
            st.insert(c[0] + " " + c[1]);
            st.insert(c[0] + " " + c[0]);
            st.insert(c[1] + " " + c[0]);
            st.insert(c[1] + " " + c[1]);
        }
        for (int i = 0; i < words1.size(); i++)
        {
            unordered_set<string>::iterator it1 = st.find(words1[i] + " " + words2[i]);
            unordered_set<string>::iterator it2 = st.find(words2[i] + " " + words1[i]);
            if ((it1 == st.end() && it2 == st.end() && words1[i] == words2[i]) ||
                it1 != st.end() || it2 != st.end())
                continue;
            else
                return false;
        }
        return true;
    }
};
int main()
{
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
