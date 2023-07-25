#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
	int hour, minute, second;

		for(hour = 0; hour < 24; hour++)
		{
			for(minute = 0; minute < 60; minute++)
			{
				for(second = 0; second < 60; second++)
				{
					printf("%d:%d:%d\n", hour, minute, second);
					sleep(1);
					system("clear");
				}
			}
		}

		
	return 0;
}
