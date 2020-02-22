// leetcode_1133.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        unordered_map<int, vector<int>> st;
        unordered_map<int, vector<int>>::iterator it;
        for (int i = 0; i < A.size(); i++)
        {
            it = st.find(A[i]);
            if (it == st.end())
            {
                vector<int> v = { i };
               //st.insert(make_pair(A[i], v));
                st.emplace(make_pair(A[i], v));
            }
            else
               ///(*it).second.push_back(i);
                (*it).second.emplace_back(i);
        }
        for (it = st.begin(); it != st.end(); it++)
            if ((*it).second.size() > 1)
            {
                for (int i = 0; i < (*it).second.size(); i++)
                    A[(*it).second[i]] = INT_MIN;
            }
        int ret = INT_MIN;
        for (int i = 0; i < A.size(); i++)
            if (ret < A[i])
                ret = A[i];
        return ret == INT_MIN?-1:ret;
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
