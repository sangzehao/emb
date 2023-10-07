#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>
#include "person.h"

using namespace std;

class Student: public Person
{
	public:
		Student(){cout << "student no argument construct function" << endl;}
		Student(int age, const char* name):Person(age), m_name(name){cout << "student have argument construct function" << endl;}
		~Student(){cout << "student end function" << endl;}
	protected:
		 const char *m_name;

};

#endif
