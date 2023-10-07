#include "student.h"
#include "person.h"

int main(void)
{
	Student s("san", 20, 99);
	Person p("si", 30);

	Person *t;

	t = &s;

	p.show();
	s.show();//隐藏
	s.Person::show();//可以这样用子类调用父类的方法
	t->show();//加virtual即为重写(覆盖)

	return 0;
}
