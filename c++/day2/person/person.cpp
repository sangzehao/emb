#include <iostream>
#include <cstring>
#include "person.h"

using namespace std;


Person::~Person(void)
{
	cout << "析构" <<endl;
}

//成员变量初始化，引用只能初始化，不能赋值
Person::Person(int r):m_r(r), m_age(0), m_height(0.0)
{
	memset(m_name, '\0', NAMESIZE);
}

Person::Person(int r, int age, float height, const char *name):m_r(r)
{
	//成员变量赋值，不同于初始化
	m_age = age;
	m_height = height;
	strncpy(m_name, name, NAMESIZE);
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

