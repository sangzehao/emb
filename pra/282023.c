#include<stdio.h>
//选择排序是找出每轮最小的，直接插入排序是默认前边是排好的，只和前边那一个交换
int main()
{
	int arr[10], tem, mid, i, j;
	
	printf("输入10个数：");
	for(i = 0; i < 10; i++){
		scanf("%d", &arr[i]);
	}
	printf("原始数据为：");
	for(i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	for(i = 0; i < 10; i++)
	{
		j = i + 1;
		for(j; j < 10; j++)
		{
			if(arr[j] < arr[i]){
				mid = arr[j];
				arr[j] = arr[i];
				arr[i] = mid;
			}
		}
	}
	printf("排序后数据为：");
	for(i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
