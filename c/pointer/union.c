#include<stdio.h>

typedef union{
	char a;
	long b;
	short c;
}un;

union ut{
	char a;
	long c;
	char b;
};

int main(void)
{
	union ut p;
	un s;

	s.b = 0x12345678;
	p.c = 0x12345678;

	int number = 0x12345678;

	char *t = (char *)&number;

	printf("%x\n", *t);

	printf("%x\n", s.a);	
	printf("%x\n", s.c);

	return 0;
}
