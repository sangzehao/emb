#include <cstring>
#include "7_person.h"

int main(void)
{

	//类实例化对象， 局部变量
	Person person1; 
	Person person2(18);

	//对象取成员, 如果是公共属性时
/*	person1.m_age = 20;
	person1.m_height = 180;
	strncpy(person1.name, "who", NAMESIZE);
*/

	//封装, 类外边不能访问类内部的属性
	person1.setName("who");
	person1.setAge(21);
	person1.setHeight(180);

	person1.show();
	person2.show();

	return 0;
}
