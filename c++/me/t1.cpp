#include <iostream>

using namespace std;

class Person{
	public:
		void getA1(){cout << a1 << endl;}//子类不可以继承a1，但可以继承这个方法，照样可以输出
		void show(){
			a1 = 20;
		}

	private:
		int a1;
};

class Child: Person{
	public:
/*
		void show(){
			a1 = 10;
			cout << a1 << endl;
		}
*/
};

int main(void)
{
	Person person;

	person.show();
	person.getA1();

	Child child;

	child.getA1();
//	child.show();
	
	return 0;
}
