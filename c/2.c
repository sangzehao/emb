#include<stdio.h>

int main(void){
	int m, n;

	scanf("%d%d", &m, &n);

	printf("%d\n", m >0 && n < 100);
	printf("%d\n", m > 0 && n ++);
	printf("n:%d\n", n);

	printf("%d\n", m > 0 || n < 100);
	printf("%d\n", !(m > 0 || n++));
	printf("n:%d\n", n);
	printf("%s\n", m % 2 == 0 ? "偶数" : "奇数");
	printf("m:%d n:%d\n", m, n);
	m = (n++, m++, m + n);
	printf("m:%d\n", m);

	return 0;
}
