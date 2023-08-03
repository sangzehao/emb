#include<stdio.h>

typedef struct{
	char a;
	char b;
	int c;
	int d;
	short e;
}s_1;

typedef struct{
	char a;
	long double b;
	s_1 n;
}s_2;

typedef struct{
	char a;
	int b;
	long c;
	double d;
	short s;
	s_1 y;
	s_2 z;
}s_3;

int main(void){
	
	s_1 s1;
	s_2 s2;
	s_3 s3;

	printf("sizeof(double)：%ld\n", sizeof(double));
	printf("sizeof(s3):%ld\n", sizeof(s3));
	printf("sizeof(short:%ld\n", sizeof(short));
	printf("sizeof(s1):%ld\n", sizeof(s1));
	printf("s1.a:%p\n", &s1.a);
	printf("s1.b:%p\n", &s1.b);
	printf("s1.c:%p\n", &s1.c);
	printf("s1.d:%p\n", &s1.d);
	printf("s1.e:%p\n", &s1.e);
	printf("sizeof(s2):%ld\n", sizeof(s2));
	return 0;
}
