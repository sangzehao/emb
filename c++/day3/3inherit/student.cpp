#include <iostream>
#include "student.h"

using namespace std;

void Student::test()
{
	// cout << m_age << endl;基类private派生类不可见
	cout << m_height << endl;	
	cout << m_name << endl;	
}

