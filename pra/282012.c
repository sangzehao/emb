# include <stdio.h>

int main(void)
{
	int day, num;
	float money, ave;
	float price = 0.8;
	
	day = 0;
	for (num = 2; num<100; num = num * 2){
		money += price * num;
		day++;
	}
		ave = money / day;
		printf("每天平均花%3f\n", ave);

	return 0;
}
