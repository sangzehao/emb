#include <iostream>
#include "teacher.h"

Teacher::Teacher():Person(), m_salary(0.0){}

Teacher::Teacher(int age, float salary, float height, const char *name):Person(age, height, name), m_salary(salary)
{
	cout << "teacher类的构造方法" << endl;
}
