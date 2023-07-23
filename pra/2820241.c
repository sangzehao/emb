#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void print(int a[], int len);
void merge(int arr[], int tempArr[], int left, int mid, int rght);
void msort(int arr[], int tempArr[], int left, int right);
void merge_sort(int arr[], int n);

int main(void)
{
	int a[10], i, mid;

	srand(time(NULL));
	for(i = 0; i < 10; i++){
		a[i] = rand() % 100; 
	}
	printf("原始数组为：");
	print(a, 10);
	//归并排序入口
	merge_sort( a, 10);
	printf("排序后为：");
	print(a, 10);

	return 0;
}

void print(int a[], int len)
{
	int i;

	for(i = 0; i < len; i++){
		printf("%2d ", a[i]);
	}
	printf("\n");
}
void merge(int arr[], int tempArr[], int left, int mid, int right)
{
	int l_pos = left;
	int r_pos = mid + 1;
	int pos = left;

	while(l_pos <= mid && r_pos <= right){
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
	while(left <= right){
		arr[left] = tempArr[left];
		left++;
	}
}

void msort(int arr[], int tempArr[], int left, int right)
{
	int mid;

	mid = (left + right) / 2;
	if(left < right){//一直分到每组一个元素
		msort(arr, tempArr, left, mid);
		msort(arr, tempArr, mid + 1, right);
		merge(arr, tempArr, left, mid, right);//递归，先往下分，再往上合
	}
}

void merge_sort(int arr[], int n)
{
//	int tempArr[10]; 也可以，创建一个临时数组
	int* tempArr = (int*) malloc (n * sizeof(int));
	
	if(tempArr){
		msort(arr, tempArr, 0, n - 1);//归并 需要left right
		free(tempArr);
	}
	else{
		printf("error");
	}
}

