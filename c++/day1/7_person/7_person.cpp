#include "7_person.h"
#include <iostream>
#include <cstring>

using namespace std;

Person::Person(int age, float height, const char *name)
{
	//成员变量初始化
	m_age = age;
	m_height = height;
	strncpy(m_name, name, NAMESIZE);
}

void Person::show(){
	cout << m_name << "今年" << m_age << "岁， 身高" << m_height << endl;
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

