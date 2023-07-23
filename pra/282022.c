#include<stdio.h>

int main(void)
{
	
	return 0;
}

int kuaisu_sort(int arr, int len)
{
	int mid, i, count, j, basis;

	for(i = 0; i < len; i++){//确定基准点；
		basis = s[i];
		for (j = len - 1; j >= 0; j--){
			if(basis > s[j]){
				mid = basis;
				basis = s[j];
				s[j] = mid;
			}
		}
	}
}
