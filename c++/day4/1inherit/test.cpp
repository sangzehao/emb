#include <iostream>

using namespace std;

class Parent{
	public:
		Parent();
		Parent(int h):height(h){cout << "Parent" << endl;}
		int height;
};

class Child : public Parent{
	public:
		Child();
		//Child():Parent(), age(0){}
		int age;
};

int main(void)
{
	Parent P(10);
	Child C;


//	C.height = 2;

	cout << P.height << endl;
//	cout << C.height << endl;

	return 0;
}
