#include <iostream>
#include <cstring>
#include "person.h"

using namespace std;

Person::Person(void)
{
	cout << "Person:" << endl;
}

void Person::show()
{
	cout << m_name << "身高" << m_height << ", 年龄" << m_age << endl;
}

void Person::setAge(int age)
{
	m_age = age;
}

void Person::setHeight(int height)
{
	m_height = height;
}

void Person::setName(const char *name)
{
	strncpy(m_name, name, NAMESIZE);
}

