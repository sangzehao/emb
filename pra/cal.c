#include<stdio.h>

int main(void)
{
	int year, month, day, sum, i, count, num;
	
	sum = 0;
	count = 0;
	printf("scanf month, year\n");
	scanf("%d%d", &month, &year);
	for(i = 1970; i < year; i++)
	{
		if((0 == i % 4 && 0 != i % 100) || 0 == i % 400)
			sum += 366;
		else
			sum += 365;
	}
	switch(month - 1)
	{
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
			if((0 == year % 4 && 0 != year % 100) || (0 == year % 400) )
				sum += 29;
			else
				sum += 28;
		case 1:
			sum += 31;
			break;
	}
	sum = sum + 1;
	printf("      %d月  %d\n", month, year);
	printf("日 一 二 三 四 五 六 \n");
	num = (sum + 3) % 7;
	for(i = 0; i < num; i++)
	{
		printf("   ");
		count++;
	}

	switch(month)
	{
		case 12:
			day = 31;
			break;
		case 11:
			day = 30;
			break;
		case 10:
			day = 31;
			break;
		case 9:
			day = 30;
			break;
		case 8:
			day = 31;
			break;
		case 7:
			day = 31;
			break;
		case 6:
			day = 30;
			break;
		case 5:
			day = 31;
			break;
		case 4:
			day = 30;
			break;
		case 3:
			day = 31;
			break;
		case 2:
			if((0 == year % 4 && !0 == year % 100) || (0 == year % 400) )
			{
				day = 29;
				break;
			}
			else
			{	
				day = 28;
				break;
			}
		case 1:
			day = 31;
			break;
	}
	for(i = 1; i <= day; i++)
	{
		if(count % 7 == 0 && count != 0)
			printf("\n");
		printf("%2d ", i);
		count++;
	}
	printf("\n");
	

	return 0;
}
