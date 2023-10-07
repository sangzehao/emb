#include <iostream>
#include <cstring>
#include "student.h"
#include "person.h"

using namespace std;

/*Student::Student():m_a(0), m_height(0), m_no(0){
	memcpy(m_name, 0, NAMESIZE);
	cout << "Student默认构造方法" << endl;
}
*/
void Student::test()
{
	cout << m_height << endl;
	cout << m_name << endl;
}

void Student::show()
{
	cout << "show" << endl;
	cout << m_height << endl;
	cout << m_name << endl;

}
