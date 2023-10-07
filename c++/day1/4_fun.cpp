#include <iostream>

using namespace std;

//函数参数默认值，在函数声明和函数定义中只能声明一次。建议设置在声明中，因为调用时可以看到。如果默认参数还有参数，则那些参数也必须带有默认值

int square_n(int num, int n = 2);

int main(void)
{
	int val = 10;

  	cout << square_n(val) << endl;
	cout << square_n(val, 3) << endl;

	return 0;	
}

int square_n(int num, int n)
{
	int res = 1;

	while(n > 0)
	{
		res *= num;
		n--;
	}

	return res;
}
