#include <iostream>
#include "teacherStudent.h"

using namespace std;

void TeacherStudent::setA(int a)
{
	m_a = a;
}

TeacherStudent::TeacherStudent(int age, float height, float salary, int no, const char *name):Student(no, 10, 180, "blank"), Person(age, height, name), Teacher(age, salary, height, name)
{

}

void TeacherStudent::show()
{
	cout << "age:" << m_age << endl;
	cout << "height:" << m_height << endl;
	cout << "no:" << m_no << endl;
	cout << "salary:" << m_salary << endl;
	cout << "name:" << m_name << endl;
}
