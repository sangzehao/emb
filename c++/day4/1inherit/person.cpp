#include <cstring>
#include <iostream>
#include "person.h"

using namespace std;

Person::Person():m_age(0), m_height(0.0)
{
	cout << "Preson 默认构造方法" << endl;
	memset(m_name, '\0', NAMESIZE);
}

Person::Person(int age, float height, const char *name)
{
	cout << "person类的带参构造方法" << endl;
	m_age = age;
	m_height = height;
	strncpy(m_name, name, NAMESIZE);
}

void Person::show()
{
	cout << m_name << "今年" << m_age << "岁, 身高" << m_height << endl;
}

void Person::setName(const char *name)
{
	strncpy(m_name, name, NAMESIZE);
}

void Person::setAge(int age)
{
	m_age = age;
}

void Person::setHeight(float height)
{
	m_height = height;
}

Person::~Person()
{
	cout << "Person析构方法调用了" << endl;
}

