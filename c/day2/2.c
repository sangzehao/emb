#include<stdio.h>

int main(void)
{
	int a, b, c, t;

	printf("输入3个数：");
	scanf("%d%d%d", &a, &b, &c);

	if(a < b){
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	if(b < c){
		b = b ^ c;
		c = b ^ c;
		b = b ^ c;
	}
	if(a < b){
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}






/*	if(a < b){
		t = a;
		a = b;
		b = t;
	}
	if(b < c){
		t = c;
		c = b;
		b = t;
	}
	if(a < b){
		t = a;
		a = b;
		b = t;
	}
*/
	printf("从大到小顺序为：%d %d %d\n", a, b,c);

	return 0;
}
