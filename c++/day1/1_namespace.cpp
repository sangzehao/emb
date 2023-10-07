#include <iostream>

namespace myname{
	int num;
	float height;
	//可以嵌套命名空间
	namespace name{
		int n;
	}
}//不加分号

int main(void)
{
	//::作用域运算符，
	myname::num = 10;
	using namespace myname;
	height = 19.2;
	myname::name::n = 2;


//	cout << num << endl; std命名空间里有cout和endl
//	cout << height << endl;
	std::cout << num << std::endl;
	std::cout << height << std::endl;
	std::cout << myname::name::n << std::endl;

	return 0;
}
