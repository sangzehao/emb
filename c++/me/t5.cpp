#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class A{
	public:
		A(){cout << "A的无参构造方法" << endl;}
		~A(){cout << "A的析构方法" << endl;}
};

class Test{
	public:
		Test() : m_a(0), m_p(NULL) {cout << "Test无参构造方法被调用了" << endl;}
		Test(int a);

		//拷贝构造方法
		Test(const Test &t);
		~Test();

	public:
		int m_a;
		int *m_p;
		A a;
};

Test::Test(int a):m_a(a)
{
	this->m_p = new int[a];
	cout << "Test 带参的构造方法" << endl;
}

Test::~Test()
{
	cout << "Test析构方法被调用" << endl;
	delete[] m_p;
	m_p = NULL;
}

//拷贝构造函数
Test::Test(const Test &t)
{
	this->m_p = new int[t.m_a];
	this->m_a = t.m_a;

	//数据copy
	memcpy(this->m_p, t.m_p, this->m_a * sizeof(int));
}

int main(void)
{
	Test t;
	Test t2(10);

	Test *t3 = new Test(5);
	int i;

	for(i = 0; i < t3->m_a; i++)
		(t3->m_p)[i] = i + 1;

	//两种拷贝方式
	Test t4 = *t3;
	Test t5(t4);

	for(i = 0; i < t4.m_a; i++)
		cout << (t4.m_p)[i] << " ";
	cout << endl;

	delete t3;
	
	return 0;
}
