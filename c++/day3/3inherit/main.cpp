#include <cstring>
#include "person.h"
#include "student.h"

int main(void)
{
	Student s;
	Student s2(18, 180, "李四");

	s.setAge(20);
	s.setName("张三");
	s.setHeight(190);
	s.test();
	std::strcpy(s.m_name, "王五");
	// s.m_height = 100;

	s.show();
	s2.show();

	return 0;
}

