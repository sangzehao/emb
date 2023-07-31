#include<stdio.h>

int main(void)
{
	int n, stu, t;
	
	for(n = 11; 1; n++)
	{	
		stu = 1;
		t = n;
		while(t > 0)
		{
			if((t - stu) % 10 != 0)
				break;
			t = t - (stu + (t - stu) / 10);
			stu ++;
		}
		if(0 == t)
		{
			printf("stu:%d\n", stu - 1);
			printf("total:%d\n", n);
			break;
		}
	}

	return 0;
}
