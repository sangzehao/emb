#include<stdio.h>
//希尔排序

int xier_pai(int s[], int len);

int main(void){
	
	int arr[10], i, num;

	printf("输入10个数:");
	for (i = 0; i < 10; i++){
		scanf("%d", &arr[i]);
	}	printf("原始数据为：");
	for (i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	xier_pai(arr, 10);
	printf("\n");
	printf("排序后：");
	for (i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

int xier_pai(int s[], int len)
{
	int step, i, mid, j;

		step = len / 2;
		while(step){
			for( i = step; i < len; i++){
				mid = s [i];
				j = i - step;
				while( (j >= 0)&& mid < s[j])
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
