// leetcode_1114.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <semaphore.h>
class Foo {
private:
	sem_t one,two;
public:
	Foo() {
	}

	void first(function<void()> printFirst) {
		printFirst();
		sem_post(&one);
	}

	void second(function<void()> printSecond) {
		sem_wait(&one);
		printSecond();
		sem_post(&two);
	}

	void third(function<void()> printThird) {
		sem_wait(&two);
		printThird();
	}
};
int main()
{
    return 0;
}

