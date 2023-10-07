#include <iostream>
#include "person.h"

using namespace std;

Person::Person(const char *name, int age):_name(name), _age(age)
{
}

void Person::show()
{
	cout << _name << "今年" << _age << "岁." << endl;
}
