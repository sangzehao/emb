#include <iostream>
#include "test.h"

using namespace std;

Test::Test(int a):m_a(a){
	m_p = new int[a];
	cout << "有参数构造方法" << endl;
}

Test::~Test(void)
{
	delete[] m_p;
	cout << "析构方法" <<endl;
}
