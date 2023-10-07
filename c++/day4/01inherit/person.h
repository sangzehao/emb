#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>

using namespace std;

class Person{
	public:
		Person(){cout << "person no argument construct function" << endl;}
		Person(int age):m_age(age){cout << m_age << " Person have argument construct function" << endl;}
		~Person(){cout << "Person end function" << endl;}
	protected:
		int m_age;
};

#endif
