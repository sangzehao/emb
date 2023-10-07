#ifndef __TEACHER_H__
#define __TEACHER_H__

#include "person.h"
#include <iostream>

using namespace std;

class Teacher : virtual public Person{
	public:
		Teacher();
		Teacher(int age, float salary, float heightm, const char *name);
		~Teacher(){cout << "Teacher类的析构方法" << endl;}
	protected:
		float m_salary;

};

#endif
