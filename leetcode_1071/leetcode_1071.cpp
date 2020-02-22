// leetcode_1071.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    bool check(string tar, string gcd)
    {
        int len = gcd.size();
        int pos = 0;
        while (pos < tar.size())
        {
            if ((pos = tar.find(gcd,pos)) == tar.npos)
                return false;
            pos += len;
        }
        return true;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int count = 1;
        int n1 = str1.size();
        int n2 = str2.size();
        string ret = "";
        while (count <= n2)
        {
            if (n2 % count == 0)
            {
                int len = n2 / count;
                string gcd = str2.substr(0, len);
                if (check(str2, gcd) && n1%len == 0 && check(str1,gcd))
                    return gcd;
            }
            count++;
        }
        return ret;
    }
};

class Solution {
private:
    int gcd(int a, int b)
    {
        while (b)
        {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1)
            return "";
        return str1.substr(0,gcd(str1.size(),str2.size()));
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
