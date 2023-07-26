#include<stdio.h>

int *jiheA(int *a);

int main(void)
{	
	int a[5], b[5];
	int i;

	jiheA(a);
	for(i = 0; i < 5; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}

int *jiheA(int *a){
	int i, j;
	for(i = 0; i < 5; i++){
		scanf("%d", (a + i));
		for(j = 0; j < i; j++){
			if(*(a + j) == *(a + i)){
				printf("重复，重新输入 ");
				i--;
				break;
			}
		}
	}

	return  a;
}
