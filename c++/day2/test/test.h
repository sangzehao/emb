#ifndef __TEST_H__
#define __TEST_H__

#include <iostream>

using namespace std;

class A{
	public:
		A(){cout << "A的构造方法" << endl;};
		~A(){cout << "A的析构方法" << endl;};
};

class Test{
	public:
		Test():m_a(0), m_p(NULL){ cout << " Test无参构造方法数" << endl;}//没有参数时的构造方法
		Test(int a);
   		~Test();

	public:
		int m_a;
		int *m_p;
		A a;
};

#endif
