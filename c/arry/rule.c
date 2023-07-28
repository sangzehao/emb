#include<stdio.h>

void p_out(int a[], int len);

int main(void)
{
	int a1[10];
	int a2[1000] = {1, 2};
	int a3[] = {1, 2, 3, 4, 5, 6, 7};
	int i;
	
	printf("a1:");
	p_out(a1, 10);
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		a1[i] = i + 1;
		printf("%d ", a1[i]);
	}
	printf("\n");
	printf("a2:");
	p_out(a2, 10);
	printf("a3:");
	p_out(a3, 7);
	printf("%p\n", &a3);

	return 0;
}

void p_out(int a[], int len)
{
	int i;

	for(i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

}
