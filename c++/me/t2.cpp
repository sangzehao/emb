#include <iostream>

using namespace std;

//重载函数：参数类型或参数个数不同

class printDate{
	public:
		void print(int i){cout << "整型数:" << i << endl;}
		void print(double i){cout << "浮点数:" << i << endl;}
		void print(char c[]){cout << "字符串:" << c << endl;}
		void print(int a, double b){cout << a + b << endl;}
};

int main(void)
{
	printDate p;

	int a = 10;
  	double b = 2.3;
	char c[] = "hello";

	p.print(a);
	p.print(b);
	p.print(c);
	p.print(a, b);

	return 0;
}
