#include <iostream>
#include "person.h"
#include "student.h"

using namespace std;

int main(void)
{
	Person *p;

	p = new Person(12, "haha");
	p->show();

	p = new Student(13, "xixi", 99);
	p->show();

	return 0;
}
