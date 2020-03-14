// leetcode_1116.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <atomic>

//condition_variable + unique_lock + atomic + memory_order
//function pointer, mutex, std::this_thread::yield(), conditional_variable + unique_lock, atomic

using namespace std;

class ZeroEvenOdd1 {
private:
	int n;
	function<void(int)> fncOdd, fncEven;
public:
	ZeroEvenOdd(int n) {
		this->n = n;
		fncOdd = fncEven = 0;
	}

	// printNumber(x) outputs "x", where x is an integer.
	void zero(function<void(int)> printNumber) {
		while (!fncOdd || !fncEven)
			std::this_thread::yield();
		for (int i = 0; i < n; i++)
		{
			printNumber();
			if (i & 1)
				fncOdd();
			else
				fncEven();
		}
	}

	void even(function<void(int)> printNumber) {
		fncEven = printNumber;
	}

	void odd(function<void(int)> printNumber) {
		fncOdd = printNumber;
	}
};

class ZeroEvenOdd2 {
private:
	int n;
	mutex mZero, mEven, mOdd;
public:
	ZeroEvenOdd(int n) {
		this->n = n;
		mEven.lock();
		mOdd.lock();
	}

	// printNumber(x) outputs "x", where x is an integer.
	void zero(function<void(int)> printNumber) {
		for (int i = 1; i <= n; i++)
		{
			mZero.lock();
			printNumber(0);
			if (i & 1)
				mOdd.unlock();
			else
				mEven.unlock();
		}
	}
	void even(function<void(int)> printNumber) {
		for (int i = 2; i <= n; i += 2)
		{
			mEven.lock();
			printNumber(i);
			mZero.unlock();
		}
	}

	void odd(function<void(int)> printNumber) {
		for (int i = 1; i <= n; i += 2)
		{
			mOdd.lock();
			printNumber(i);
			mZero.unlock();
		}
	}
};

class ZeroEvenOdd3 {
private:
	volatile int n;
	volatile int idx;
public:
	ZeroEvenOdd(int n) {
		this->n = n << 1;
		idx = 1;
	}

	// printNumber(x) outputs "x", where x is an integer.
	void zero(function<void(int)> printNumber) {
		while (idx <= n)
		{
			if ((idx & 1))
			{
				printNumber(0);
				++idx;
			}
			std::this_thread::yield();
		}
	}
	void even(function<void(int)> printNumber) {
		while (idx <= n)
		{
			if (!(idx & 1) && !((idx >> 1) & 1))
			{
				printNumber(idx >> 1);
				++idx;
			}
			std::this_thread::yield();
		}
	}

	void odd(function<void(int)> printNumber) {
		while (idx <= n)
		{
			if (!(idx & 1) && ((idx >> 1) & 1))
			{
				printNumber(idx >> 1);
				++idx;
			}
			std::this_thread::yield();
		}
	}
};

class ZeroEvenOdd4 {
private:
	condition_variable condVar;
	mutex mu_;
	int idx;
	int n;
public:
	ZeroEvenOdd(int n) {
		this->n = n;
		idx = 1;
	}

	// printNumber(x) outputs "x", where x is an integer.
	void zero(function<void(int)> printNumber) {
		for (int i = 1; i <= n; i++)
		{
			unique_lock<mutex> lck(mu_);
			condVar.wait(lck, [=]() {return idx & 1; });
			printNumber(0);
			++idx;
			condVar.notify_all();
		}
	}
	void even(function<void(int)> printNumber) {
		for (int i = 2; i <= n; i += 2)
		{
			unique_lock<mutex> lck(mu_);
			condVar.wait(lck, [=]() {return !(idx & 1) && !((idx >> 1) & 1); });
			printNumber(idx >> 1);
			++idx;
			condVar.notify_all();
		}
	}

	void odd(function<void(int)> printNumber) {
		for (int i = 1; i <= n; i += 2)
		{
			unique_lock<mutex> lck(mu_);
			condVar.wait(lck, [=]() {return !(idx & 1) && ((idx >> 1) & 1); });
			printNumber(idx >> 1);
			++idx;
			condVar.notify_all();
		}
	}
};
class ZeroEvenOdd {
private:
	enum class State { ZERO_ODD, ODD, ZERO_EVEN, EVEN };
	atomic<State> st;
	volatile int n;
public:
	ZeroEvenOdd(int n) {
		this->n = n;
		st.store(State::ZERO_ODD, memory_order_relaxed);
	}

	// printNumber(x) outputs "x", where x is an integer.
	void zero(function<void(int)> printNumber) {
		for (int i = 1; i <= n; )
		{
			State s;
			if ((s = st.load(std::memory_order_relaxed)) == State::ZERO_ODD) {
				printNumber(0);
				st.store(State::ODD, std::memory_order_relaxed);
				++i;
			}
			else if (st == State::ZERO_EVEN) {
				printNumber(0);
				st.store(State::EVEN, std::memory_order_relaxed);
				++i;
			}
			this_thread::yield();
		}
	}
	void even(function<void(int)> printNumber) {
		for (int i = 2; i <= n;)
		{
			State s = st.load(std::memory_order_relaxed);
			if (s == State::EVEN)
			{
				printNumber(i);
				i+=2;
				st.store(State::ZERO_ODD, memory_order_relaxed);
			}
			this_thread::yield();
		}
	}

	void odd(function<void(int)> printNumber) {
		for (int i = 1; i <= n;)
		{
			State s = st.load(std::memory_order_relaxed);
			if (s == State::ODD)
			{
				printNumber(i);
				i+=2;
				st.store(State::ZERO_EVEN, memory_order_relaxed);
			}
			this_thread::yield();
		}
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
