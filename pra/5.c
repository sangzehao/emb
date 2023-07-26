#include<stdio.h>

int xuanze_sort(int s[], int len);

int main(void){

	int arr[10], i;

	printf("10个数：");
	for(i = 0; i < 10; i++){
		scanf("%d", &arr[i]);
	}
	xuanze_sort(arr, 10);
	printf("\n");
	for (i = 0; i < 10; i++){
		printf("%d", arr[i]);
	}


	return 0;
}

int xuanze_sort(int s[], int len){
	int mid, i, j, temp;

	for(i = 0; i < len; i++){
		mid = s[i];
		j = i + 1;
		for (j; j < len; j++){
			if (s[j] < mid)
			{
				temp = s[j];
				s[j] = mid;
				mid = temp;
			}
		}
		s[i] = mid;
	}

}
