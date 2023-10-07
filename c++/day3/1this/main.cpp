#include <iostream>
#include "test.h"

using namespace std;

int main(void)
{
	A obja;
	B objb;
	B objc;

	cout << sizeof(obja) << endl;
	cout << sizeof(objb) << endl;
	cout << sizeof(objc) << endl;
	cout << sizeof(A) << endl;

	objb.setA(100);//第一个参数是隐形参数，this指针，作用是能知道哪个对象调用这个函数
	objc.setA(20);

	return 0;
}
