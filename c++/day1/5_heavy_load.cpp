#include <iostream>

using namespace std;

void swap2num(int *a, int *b);
void swap2num(float *a, float *b);

int main(void)
{
	int a, b;
	float f1, f2;
	
	a = 1;
	b = 2;
	f1 = 2.2;
	f2 = 3.3;

	swap2num(&a, &b);
	swap2num(&f1, &f2);

	cout << a << b << endl;
	cout << f1 << f2 << endl;
	
	return 0;
}

void swap2num(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

void swap2num(float *a, float *b)
{
	float t;

	t = *a;
	*a = *b;
	*b = t;
}
