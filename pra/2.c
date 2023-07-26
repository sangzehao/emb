#include<stdio.h>

int zhijie_sort(int s[], int len);

int mian(void){
	int arr[10], i;

	printf("输入10个数：");
	for(i = 0; i < 10; i++){
		scanf("%d", arr[i]);
	}
	printf("\n");
	printf("原始数据为：");
	for(i = 0; i < 10; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
	
	zhijie_sort(arr, 10);
	printf("排序后数据为：");
	for(i = 0; i < 10; i++){
		printf("%d", arr[i]);
	}
	printf("\n");

	return 0;
}

int zhijie_sort(int s[], int len)
{
	int mid, i, j, tem;

	for(i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1; j++){	
			if (s[j] > s[j + 1])
			{
				tem = s[j];
				s[j] = s[j - 1];
				s[j - 1] = s[j];
			}
		}
	}
