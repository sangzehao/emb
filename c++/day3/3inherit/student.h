#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>
#include "person.h"

using namespace std;

// 派生类Student
class Student : public Person {
	public:
		// 初始化列表的方式调用基类的构造方法
		Student():Person() { cout << "Student构造方法" << endl;}
		Student(int age, int height, const char *name):Person(age, height, name){cout << "Student带参构造方法" << endl;} 
		~Student() {cout << "Student析构方法" << endl;}
		void test();
};

#endif

