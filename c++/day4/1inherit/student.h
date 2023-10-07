#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>
#include "person.h"

using namespace std;

class Student : virtual public Person{
	public:
		Student():Person(), m_no(0){cout << "Student构造方法" << endl;}
		Student(int no, int age, int height, const char *name):Person(age, height, name),m_no(no){cout << "Student带参构造方法" << endl;}
		~Student(){cout << "Student析构方法" << endl;}
		void test();
		void show();
	protected:
		int m_no;
};

#endif
