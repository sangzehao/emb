#include<stdio.h>
//直接插入排序

int insort(int s[]);

int main(void){
	int arr[10], i, num;

	printf("输入10个数:");
	for (i = 0;  i < 10; i++){
		scanf("%d", &num);
		arr[i] = num;
	}
	printf("\n");
	printf("原始数据为：");
	for(i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	insort(arr);
	printf("排序后数据为：");
	for(i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

int insort(int s[]){
	int i, mid, j;

	for(i = 1; i < 10; i++){
		mid = s[i];
		j = i;
		while(mid < s[j -1 ]){
			s[j] = s[j - 1];
			j--;
		   if(0 == j)
		   		break;  //j == 0 时，s[-1]错了 
		}
		s[j] = mid;
	}
	return 0;
}
