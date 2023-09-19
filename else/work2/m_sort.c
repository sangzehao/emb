#include <stdio.h>
#include <stdlib.h>

void show_arr(int *arr, int len);
void sort(int arr[], int tempArr[], int left, int mid, int right);
int merge_sort(int arr[], int tempArr[], int left, int right);
void merge(int arr[], int len);

int main(void)
{
	int arr[10] = {9,3,4,5,1,7,6,2,8,0};
	show_arr(arr, 10);
	merge(arr, 10);
	show_arr(arr, 10);

	return 0;
}

void show_arr(int *arr, int len)
{
	int i;

	for(i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void sort(int arr[], int tempArr[], int left, int mid, int right)
{
	int l_pos = left;
	int r_pos = mid + 1;
	int pos = left;

	while(l_pos <= mid && r_pos <= right)
	{
		if(arr[l_pos] > arr[r_pos])
			tempArr[pos++] = arr[r_pos++];
		else
			tempArr[pos++] = arr[l_pos++];
	}
	while(l_pos <= mid)
	{
		tempArr[pos] = arr[l_pos];
		pos++;
		l_pos++;
	}
	while(r_pos <= right)
	{
		tempArr[pos] = arr[r_pos];
		pos++;
		r_pos++;
	}
/*	while(left <= right){
		arr[left] = tempArr[left];
		left++;
	}
*/
/*	while(l_pos <= mid)
		tempArr[pos++] = arr[l_pos++];
   	while(r_pos <= right)
	    tempArr[pos++] = arr[r_pos++];
*/
	while(left <= right)
		arr[left++] = tempArr[left];//tempArr的同步到arr， 最后一次同步不行，因为不知道下一次sort从哪儿开始

}

int merge_sort(int arr[], int tempArr[], int left, int right)
{
	int mid;

	mid = (left + right) / 2;
	if(left < right)
	{
		merge_sort(arr, tempArr, left, mid);
		merge_sort(arr, tempArr, mid + 1, right);
		sort(arr, tempArr, left, mid, right);
	}

	return 0;
}

void merge(int arr[], int len)
{
	int *tempArr = (int *)malloc(len * sizeof(int));//分配一个临时数组
	
	if(tempArr != NULL)
	{
		merge_sort(arr, tempArr, 0, len - 1);
		free(tempArr);
	}else{
		printf("error!\n");
	}
}
