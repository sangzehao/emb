#include<stdio.h>

int xier_sort(int s[], int len);

int main(void){
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
	xier_sort(arr, 10);
	printf("排序后数据为：");
	for(i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

int xier_sort(int s[], int len){
	int step, i, mid, j;

	step = len / 2;
	while(step){
		for(i = step; i < len; i++)
		{
			mid = s[i];
			j = i - step;
			while(j >= 0 && mid < s[j])
			{
				s[j + step] = s[j];
				j -= step;
			}
			s[j + step] = mid;
		}
		step /= 2;
	}



}
