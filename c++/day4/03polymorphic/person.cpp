#include <iostream>
#include "person.h"

using namespace std;

Person::Person(int age, const char *name):m_age(age), m_name(name){
	cout << "P construct" << endl;
}

void Person::show()
{
	cout << m_name << "今年" << m_age << "岁" << endl;
}
