// leetcode_507.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
    public boolean checkPerfectNumber(int num) {
        /*
        1.奇数肯定不是完美数
        2.对于数字28，可以判断2-28/2范围内的可以整除的数，然后加起来看是否和28相等
        上面的方法逐个判断有冗余，因为28%2=0，28%14=0，判断了2次，我们可以减少为一次判断
        具体的，当我们知道28%2=0之后，将28/2=14的结果也保存下来，这样就不用在判断是否可以被14整除了。
         for(int i = 2; i < num / i; i++) 当i=2时，i<28/2=14，这样就排除了14
         以这种方式每次将区间的范围缩小为 i~num/i,时间O(logn)
        */
        if (num % 2 != 0) return false;

        int tmp = 1;
        for (int i = 2; i < num / i; i++) {
            if (num % i == 0) {
                tmp += i + num / i;
            }
        }

        return tmp == num;
    }
}
int main()
{
    Solution s;
    s.checkPerfectNumber(28);
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
