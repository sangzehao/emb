#include<stdio.h>

int panduan(int a);

int main(void){
	int year, month, day, sum;
	
	sum = 0;
	printf("输入年月日：");
	scanf("%d%d%d", &year, &month, &day);

	switch(month - 1){
		case 12:
			sum += 31;
		case 11:
			sum += 30;
		case 10:
			sum += 31;
		case 9:
			sum += 30;
		case 8:
			sum += 31;
		case 7:
			sum += 31;
		case 6:
			sum += 30;
		case 5:
			sum += 31;
		case 4:
			sum += 30;
		case 3:
			sum += 31;
		case 2:
			sum += (28 + panduan(year));
		case 1:
			sum += 31;
	}
	sum += day;
	printf("第%d天\n", sum);

	return 0;
}

int panduan(int a){
 	if((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
		return 1;
	else
		return 0;
}
