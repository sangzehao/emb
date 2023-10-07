#include <iostream>
#include "test.h"

using namespace std;

int main(void)
{
	//t t1栈空间
	Test t;
	Test t1(10);

	//动态开辟对象，堆空间
	Test *t3 = new Test(5);
	int i;
	
	for(i = 0; i < t3->m_a; i++)
	{
		(t3->m_p)[i] = i + 1;
	}
	//t4栈
/*	Test t4 = *t3;
	
	for(i = 0; i < t4.m_a; i++)
	{
		cout << (t4.m_p)[i] << " ";
	}
	
	cout << endl;
*/	
	delete t3;

	return 0;
}
