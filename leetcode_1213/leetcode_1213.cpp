// leetcode_1213.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution1 {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int map[2001] = { 0 };
        for (auto i : arr1)
            map[i]++;
        for (auto i : arr2)
            map[i]++;
        for (auto i : arr3)
            map[i]++;
        vector<int> vt;
        for (int i = 0; i < 2001; i++)
            if (map[i] == 3)
                vt.emplace_back(i);
        return vt;
    }
};
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> vt;
        int idx1 = 0, idx2 = 0, idx3 = 0;
        while (idx1 < arr1.size() && idx2 < arr2.size() && idx3 < arr3.size())
        {
            while (idx1 < arr1.size() && idx2 < arr2.size() && arr1[idx1] != arr2[idx2])
            {
                if (arr1[idx1] < arr2[idx2])
                    idx1++;
                if (idx1 < arr1.size() && arr1[idx1] > arr2[idx2])
                    idx2++;
            }
            while (idx1 < arr1.size() && idx3 < arr3.size() && arr1[idx1] != arr3[idx3])
            {
                if (arr1[idx1] < arr3[idx3])
                    idx1++;
                if (idx1 < arr1.size() && arr1[idx1] > arr3[idx3])
                    idx3++;
            }
            if (idx1 < arr1.size() && idx2 < arr2.size() && idx3 < arr3.size() && arr1[idx1] == arr2[idx2] && arr1[idx1] == arr3[idx3])
            {
                vt.emplace_back(arr1[idx1]);
                idx1 = idx2 = idx3 = idx1 + 1;
            }
        }
        return vt;
    }
};
int main()
{
    vector<int> vt1, vt2, vt3;
    vt1 = { 197,418,523,876,1356 };
    vt2 = { 501,880,1593,1710,1870 };
    vt3 = { 521,682,1337,1395,1764 };
    Solution s;
    s.arraysIntersection(vt1, vt2, vt3);
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
