#include "sheep.h"

//初始化静态的成员变量
int Sheep::cnt = 0;
Sheep::Sheep() : m_name("name1"), m_age(20)
{
	Sheep::cnt++;
}

Sheep::Sheep(const char *name, uint8_t age):m_name(name), m_age(age)
{
	Sheep::cnt++;
}

Sheep::~Sheep()
{
	Sheep::cnt--;
}

int Sheep::getCnt()
{
	//cout << m_name;错误，只能访问静态变量
	return cnt;
}
