// leetcode_157.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int read4(char* buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char* buf, int n) {
        int t = 0;
        while (1)
        {
            int s = read4(buf + t);
            t += s;
            if (t > n)
            {
                t = n;
                buf[n] = 0;
                break;
            }
            if (s < 4)
                break;
        }
        return t;
    }
};

class Solution1 {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char* buf, int n) {
        int t = 0;
        int r = 4;
        while (t + 4 <= n)
        {
            r = read4(buf + t);
            if (r < 4)
            {
                t += r;
                break;
            }
            t += 4;
        }
        if (t < n && r == 4)
        {
            char s[4];
            r = read4(s);
            for (int i = 0; i < n - t && i < r; i++)
                buf[t + i] = s[i];
            t += min(n - t, r);
        }

        return t;
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
