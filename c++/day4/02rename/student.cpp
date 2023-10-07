#include <iostream>
#include "student.h"

using namespace std;

Student::Student(const char *name, int age, float score):Person(name, age), _score(score){}

void Student::show()
{
	cout << _name << "学生,今年" << _age << "岁,成绩为" << _score << endl;
}
