#include<stdio.h>

int fei(int n);

int main(void)
{
	int n = 20;
	
	printf("%d\n", fei(n));

	return 0;
}

int fei(int n)
{
	int i;
	
	if(n == 1 || n == 2){
		return 1;
	}
	else{
		return fei(n - 2) + fei(n - 1);
	}
		
}
