#include <iostream>

using namespace std;

void swap2num(float *a, float *b);
void swap2num(int &a, int &b);

int main(void)
{
	int a, b;
	float f1, f2;

	a = 2;
	b = 3;
	f1 = 2.1;
	f2 = 3.2;

	swap2num(a, b);//类似于宏吧，这里a就是a,而不是a的值，里边变，外边也会变，函数结束不会消失。第一次引用后，不可以再作为别的引用
	swap2num(b, a);
	swap2num(&f1, &f2);

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "f1:" << f1<< endl;
	cout << "f2:" << f2<< endl;

	return 0;
}

//int &表示引用

void swap2num(int &a, int &b)
{
	int t;

	t = a;
	a = b;
	b = t;
}

void swap2num(float *a, float *b)
{
	float t;

	t = *a;
	*a = *b;
	*b = t;
}
