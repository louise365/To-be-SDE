// leetcode_604.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class StringIterator {
private:
    int idx;
    vector<pair<char, int>> vt;
public:
    StringIterator(string compressedString) {
        idx = 0;
        for (int i = 0; i < compressedString.size();)
        {
            if (isalpha(compressedString[i]))
            {
                int t = 1;
                int sum = 0;
                while (isdigit(compressedString[i + t]))
                {
                    sum = compressedString[i + t] - '0' + sum * 10;
                    t++;
                }
                vt.push_back(make_pair(compressedString[i], sum));
                i += t;
            }
        }
    }

    char next() {
        char ret = 0;
        if (vt.size())
        {
            ret = vt[0].first;
            if (--vt[0].second == 0)
                vt.erase(vt.begin());
        }
        return ret;
    }

    bool hasNext() {
        return !vt.empty();
    }
};
int main()
{
    StringIterator s("X10");
    s.next();
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
