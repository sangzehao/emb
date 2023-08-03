#include<stdio.h>

int main(void)
{
	int arr[10];

	int (*p)[10] = &arr;

/*	printf("arr:%p\n", arr);
	printf("arr + 1:%p\n", arr + 1);
	printf("&arr:%p\n", &arr);
	printf("&arr + 1:%p\n", &arr + 1);
	printf("p:%p\n", p);
	printf("p + 1:%p\n", p + 1);
*/
	int a[2][3];

	int (*s)[3] = a;

	printf("a:%p\n", a);
	printf("a + 1:%p\n", a + 1);
	printf("&a:%p\n", &a);
	printf("&a + 1:%p\n", &a + 1);
	printf("s:%p\n", s);
	printf("s + 1:%p\n", s + 1);

	return 0;
}
