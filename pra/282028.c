#include<stdio.h>

int main(void){
	int i;
/*	long f[31];

	f[1] = 1;
	f[2] = 1;
	for(i = 3; i < 31; i++){
		f[i] = f[i - 1] + f[i - 2];
	}
	for(i = 1; i < 31; i++){
		printf("%10ld ", f[i]);
		if(i % 5 == 0)
			printf("\n");
	}
	*/
	long f1 = 1;
	long f2 = 1;
	i = 1;

	for(i; i < 16; i++){
		printf("%10ld %10ld", f1, f2);
		if(i % 2 == 0)
			printf("\n");
		f1 = f1 + f2;
		f2 = f1 + f2;
	}
	
	return 0;
}
