#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	int *p = new int;
	char *s = new char[20];

	*p = 100;
	cout << "*p:" << *p << endl;

	strncpy(s, "hello", 20);
	puts(s);
	
	delete p;
	delete[] s;

	return 0;
}
