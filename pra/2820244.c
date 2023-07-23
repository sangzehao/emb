#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void p_out(int arr[], int len);
void merge_sort(int arr[], int len);
void merge(int arr[], int tempArr[], int left, int right);
void msort(int arr[], int tempArr[], int left, int mid, int right);

int main(void){
	int arr[10], i = 0;
	
	srand(time(NULL));
	for(i = 0; i < 10; i++){
		arr[i] = rand() % 100;
	}
	printf("原始数据为：");
	p_out(arr, 10);
	merge_sort(arr, 10);
	printf("排序后为：");
	p_out(arr, 10);
}

void msort(int arr[], int tempArr[], int left, int mid, int right)
{
	int l_pos = left;
	int r_pos = mid + 1;
	int pos = left;
	while(l_pos <= mid && r_pos <=right )
	{
		if(arr[l_pos] > arr[r_pos])
			tempArr[pos++] = arr[r_pos++];
		else
			tempArr[pos++] = arr[l_pos++];
	}
	while(l_pos <= mid)
		tempArr[pos++] = arr[l_pos++];
	while(r_pos <= right)
		tempArr[pos++] = arr[r_pos++];
	while(left <= right)
	{
		arr[left++] = tempArr[left];
	}
}

void p_out(int arr[], int len)
{
	int i = 0;

	for(i; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void merge(int arr[], int tempArr[], int left, int right)
{
	int mid = 0;

	if(left < right)
	{
		mid = (left + right) / 2;
		merge(arr, tempArr, left, mid);
		merge(arr, tempArr, mid + 1, right);
		msort(arr, tempArr, left, mid, right);
	}
}

void merge_sort(int arr[], int len)
{
	int *tempArr = (int*) malloc (len * sizeof(int));
   if(tempArr)
   {
   		merge(arr, tempArr, 0, len - 1);
		free(tempArr);
   }else{
   		printf("error!\n");
   }
}
