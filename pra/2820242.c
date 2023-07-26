#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void p_out(int a[], int len);
void merge_sort(int a[], int n);
void msort(int a[], int tempA[], int left, int right);
void merge(int a[], int tempA[], int left, int mid, int right);

int main(void)
{
	int i;
	int arr[10];

	srand(time(NULL));
	for(i = 0; i < 10; i++){
		arr[i] = rand() % 100;
	}
	p_out(arr, 10);
	merge_sort(arr, 10);
	p_out(arr, 10);

	return 0;
}

void p_out(int a[], int len)
{
	int i;

	for(i = 0; i < len; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
void merge(int a[], int tempA[], int left, int mid, int right)
{
	int l_pos = left;
	int r_pos = mid + 1;
	int pos = left;

	while(l_pos <= mid && r_pos <= right)
	{
		if(a[l_pos] > a[r_pos])
			tempA[pos++] = a[r_pos++];
		else
			tempA[pos++] = a[l_pos++];
	}
	//肯定有一个没比完
	while(l_pos <= mid)
	{
		tempA[pos++] = a[l_pos++];
	}
	while(r_pos <= right){
		tempA[pos++] = a[r_pos++];
	}
	while(left <= right)
	{
		a[left++] = tempA[left];
//		a[left++] = tempA[left++];错的 left加了两次
	}
}

void msort(int a[], int tempA[], int left, int right)
{
	int mid;

	if(left < right){
		mid = (left + right) / 2;
		msort(a, tempA, left, mid);
		msort(a, tempA, mid + 1, right);
		merge(a, tempA, left, mid, right);
	}
}

void merge_sort(int a[], int n)
{
	int * tempA = (int *)malloc(n * sizeof(int));

	if(tempA){
		msort(a, tempA, 0, n - 1);
		free(tempA);
	}else{
		printf("error\n");
	}
}
