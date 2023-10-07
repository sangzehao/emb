#include <iostream>

using namespace std;

class Parent{
	public:
		int a;
		Parent(){
			a = 0;
			a1 = 1;
			a2 = 2;
			a3 = 3;
		}
		void show()
		{
			cout << "a:" << a << endl;	
			cout << "a1:" << a1 << endl;	
			cout << "a2:" << a2 << endl;	
			cout << "a3:" << a3 << endl;	
		}
		void getA3(){
			cout << a3 << endl;
		}
		void getA2(){
			cout << a2 << endl;
		}

	public:
		int a1;
	protected:
		int a2;
	private:
		int a3;
	
};

class Children: Parent{
};

int main(void)
{
	Parent p;

	cout << "p:" << endl;
	p.show();
	p.getA3();
	p.getA2();

	cout << "c:" << endl;
	Children c;
	
	c.show();
	c.getA3();
	p.getA2();

	return 0;	
}
