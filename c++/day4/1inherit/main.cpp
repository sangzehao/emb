#include <cstring>
#include <iostream>
#include "person.h"
#include "student.h"
#include "teacherStudent.h"

using namespace std;

int main(void)
{
	TeacherStudent ts(20, 200, 100000, 5, "yao");

	ts.setA(100);
	ts.show();

	return 0;


/*	Student s;
	Student s2(1, 18, 180, "李四");
	
	s.setAge(20);
	s.setName("张三");
	s.setHeight(190);
	s.test();
	strcpy(s.m_name, "王五");

	s.show();
	s2.show();

	cout << "继承来的public:" << s.m_name << endl;
*/
}
