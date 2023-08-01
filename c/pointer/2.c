#include<stdio.h>

int deal_arr(int *p, int n, int *max, int *min, int *avg);

int main(void)
{
	int a[] = {1,2,3,4,4,5,6,7,8,8,5,4,32};
	int max, min, avg;

	deal_arr(a, sizeof(a) / sizeof(int), &max, &min, &avg);
	
	printf("min:%d max:%d avg:%d\n", min, max, avg);

	return 0;
}

int deal_arr(int *p, int n, int *max, int *min, int *avg)
{
	int i, sum;

	*min = *max = p[0];
	sum = p[0];

	for(i = 1; i < n; i++)
	{
		if(p[i] > *max)
			*max = p[i];
		if(p[i] < *min)
			*min = p[i];
		sum += p[i];
	}
	*avg = sum / n;

	return 0;
}
