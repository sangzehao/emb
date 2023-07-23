#include<stdio.h>

int main(void)
{
	int core;

	scanf("%d", &core);

	switch(core / 10)
	{
		case 10:
		case 9:
			printf("A\n");
			break;
		case 8:
			printf("B\n");
			break;
		case 7:
			printf("c\n");
			break;
		case 6:
			printf("D\n");
			break;
		default:
			printf("E\n");
			break;
	}

/*	if(core >= 90 && core <= 100){
		printf("A\n");
	}else if(core >= 80 && core <90){
		printf("B\n");
	}else if(core > 69 && core < 80){
		printf("C\n");
	}else if(core > 59 && core < 70){
		printf("D\n");
	}else{
		printf("E\n");
	}
*/
	return 0;
}
