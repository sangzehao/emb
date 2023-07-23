#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void p_out(int a[], int n);
void merge_sort(int arr[], int n);
void merge(int arr[], int tempArr[], int left, int right);
void msort(int arr[], int tempArr[], int left, int mid, int right);

int main(void)
{
	int arr[10], i;
		
	srand(time(NULL));
	for(i = 0; i < 10; i++){
		arr[i] = rand() % 100;
	}
	p_out(arr, 10);
	merge_sort(arr, 10);
	p_out(arr, 10);

	return 0;
}

void p_out(int a[], int n)
{
	int i;

	for(i = 0; i < n; i++){
		printf("%d ", a[i]);
	}

	printf("\n");
}

void msort(int arr[], int tempArr[], int left, int mid, int right)
{
	int l_pos = left;
	int r_pos = mid + 1;
	int pos  = left;

	while(l_pos <= mid && r_pos <= right)
	{
		if(arr[l_pos] > arr[r_pos])
			tempArr[pos++] = arr[r_pos++];
		else
			tempArr[pos++] = arr[l_pos++];
	}
	while(l_pos <= mid)
	{
		tempArr[pos++] = arr[l_pos++];
	}
	while(r_pos <= right)
	{
		tempArr[pos++] = arr[r_pos++];
	}
	while(left <= right)
	{
		arr[left++] = tempArr[left];
	}
}

void merge(int arr[], int tempArr[], int left, int right)
{
	int mid;
	
	if(left < right){
		mid = (left + right) / 2;
		merge(arr, tempArr, left, mid);
		merge(arr, tempArr, mid + 1, right);
		msort(arr, tempArr, left, mid, right);
	}
}

void merge_sort(int arr[], int n)
{
	int* tempArr = (int *) malloc(n * sizeof(int));

	if(tempArr){
		merge(arr, tempArr, 0, n - 1);
		free(tempArr);
	}else{
		printf("error!\n");
	}
}
