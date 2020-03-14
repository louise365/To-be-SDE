// leetcode_1391.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class AnimalShelf {
private:
    deque<int>cat, dog;
public:
    AnimalShelf() {

    }

    void enqueue(vector<int> animal) {
        if (animal[1] == 0)
            cat.emplace_back(animal[0]);
        else
            dog.emplace_back(animal[0]);
    }

    vector<int> dequeueAny() {
        int retC = -1;
        int retN = INT_MAX;
        if (!cat.empty())
        {
            if (cat.front() < retN)
            {
                retC = 0;
                retN = cat.front();
                cat.pop_front();
            }
        }
        if (!dog.empty())
        {
            if (dog.front() < retN)
            {
                if (retN != INT_MAX)
                    cat.emplace_front(retN);
                retC = 1;
                retN = dog.front();
                dog.pop_front();
            }
        }
        return vector<int>{retN == INT_MAX ? -1 : retN, retC};
    }

    vector<int> dequeueDog() {
        int retC = -1;
        int retN = INT_MAX;
        if (!dog.empty())
        {
            if (dog.front() < retN)
            {
                retC = 1;
                retN = dog.front();
                dog.pop_front();
            }
        }
        return vector<int>{retN == INT_MAX ? -1 : retN, retC};
    }

    vector<int> dequeueCat() {
        int retC = -1;
        int retN = INT_MAX;
        if (!cat.empty())
        {
            if (cat.front() < retN)
            {
                retC = 0;
                retN = cat.front();
                cat.pop_front();
            }
        }
        return vector<int>{retN == INT_MAX ? -1 : retN, retC};
    }
};
int main()
{
    std::cout << "Hello World!\n";
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
