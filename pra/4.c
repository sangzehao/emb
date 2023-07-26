#include <stdio.h>

int maopao_paixv(int s[], int len);

int main(void)
{
	int arr[10], i;
	
	printf("输入10个数：");
	for(i = 0; i < 10; i++){
		scanf("%d", &arr[i]);
	}
	maopao_paixv(arr, 10);
	printf("\n");
	for(i = 0; i < 10; i++){
		printf("%d", arr[i]);
	}

	return 0;
}

int maopao_paixv(int s[], int len){
	int mid, i, j;

	for(i = 0; i < len; i++){
		for(j = 1; j < len; j++)
			if(s[j] < s[j - 1]){
				mid = s[j];
				s[j] = s[j - 1];
				s[j - 1] = mid;
			}
	}


}
