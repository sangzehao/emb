#include "person.h"
#include "student.h"
#include <iostream>

using namespace std;

Student::Student(int age, const char *name, float score):Person(age, name), m_score(score){
	cout << "Student construct" << endl;
}

void Student::show()
{
	cout << m_name << "今年" << m_age << "岁,成绩" << m_score << endl;
}
