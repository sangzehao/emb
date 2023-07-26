#include <stdio.h>

int main(void)
{
	int num = 0;
	int year, month, day;
	int i ;

	//先判断第几天
	i = 2011;
	printf("分别输入年，月，日： ");
	scanf("%d %d %d", &year, &month, &day);
	
	//先计算年 
	for ( i; i<year; i++)
		if(( i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
			num += 366;
		else
			num += 365;	
	
	switch (month - 1){
		case 11 :
			num += 30;
		case 10 :
			num += 31;
		case 9 :
			num += 30;
		case 8 :
			num += 31;
		case 7:
			num += 31;
		case 6 :
			num += 30;
		case 5 :
			num += 31;
		case 4 :
			num += 30;
		case 3 :
			num += 31;
		case 2 :
			if(( i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
				num += 29;
			else
				num += 28;
		case 1 : 
			num += 31;
		default :
			break;
	}
	num += day;
	num--;
	printf("第%d 天\n", num);

	i = 0;
	//正着算，加单位量
	while( i <= num ){
		i += 2;
		if (i == num )
			printf("这天在晒网\n");
		i += 3;
		if (i == num ){
			printf("这天在打渔\n");	
		}
	}

	return 0;
}
