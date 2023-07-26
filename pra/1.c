#include<stdio.h>

int xier_sort(int s[], int len);

int main(void)
{
	int arr[10], i, j;

	printf("输入10个数字：");
	for (i = 0; i < 10; i++){
		scanf("%d", &arr[i]);
	}
	printf("\n");
	printf("原始数据为：");
	for (i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	xier_sort(arr, 10);
	printf("排序后为：");
	for (i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return 0;
}

int xier_sort(int s[], int len)
{
	int mid, i, j, step;

	step = len / 2;

	while(step)
	{	
		for (i = step; i < len; i++)//分为几组，然后插入排序，用后边的去跟前边的作比较。
			{
				mid = s[i];
				j = i - step;
				while((j >= 0) && mid < s[j])
				{
					s[j + step] = s[j];
					j -= step;
				}
				s[j + step] = mid;
			}	
		step = step / 2;
	}

	return 0;
}

