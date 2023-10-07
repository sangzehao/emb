#include <iostream>
#include <cstring>

#include "person.h"

using namespace std;//这个可以不写了, person.cpp里有

int main(void)
{
	//类实例化对象
	Person person1;

	person1.setAge(12);
	person1.setName("xiao");
	person1.setHeight(178);

	person1.show();

	return 0;
}
