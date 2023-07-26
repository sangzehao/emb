#include<stdio.h>

int swap(int *a, int *b, int *c);

int main(void){
	int a, b, c, *p1, *p2, *p3;
	
	p1 = &a;
	p2 = &b;
	p3 = &c;

	scanf("%d %d %d", p1, p2, p3);
	swap(p1, p2, p3);
	printf("%d %d %d\n", *p1, *p2, *p3);

	return 0;
}

int swap(int *a, int *b, int *c)
{
	int t;

	if(*a > *b){
		t = *a;
		*a = *b;
		*b = t;
	}	
	if(*b > *c){
		t = *b;
		*b = *c;
		*c = t;
	}
	if(*a > *b){
		t = *a;
		*a = *b;
		*b = t;
	}

	return 0;
}
