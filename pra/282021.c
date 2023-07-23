#include<stdio.h>

int maopao_sort(int s[], int len);

int main(void)
{
	int arr[10], i;

	printf("输入10个数：");
	for(i = 0; i < 10; i++){
		scanf("%d", &arr[i]);
	}	
	printf("原始数据为：");
	for(i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	maopao_sort(arr, 10);
	printf("排序后为：");
	for(i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

int maopao_sort(int s[], int len)
{
	int mid, i, j;

	for(i = 1; i < len; i++){
		for (j = 1; j < len; j++){
			if( s[j] < s[j - 1]){
				mid = s[j];
				s[j] = s[j - 1];
				s[j - 1] = mid;
			}
		}
	}

	return 0;
}
