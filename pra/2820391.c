#include<stdio.h>

int main(void)
{
	int stu, total, t;

	for(total = 11; ; total++)
	{
		stu = 1;
		t = total;
		while(t > 0)
		{
			if((t - stu) % 10 != 0)
				break;
			t -= (stu + (t - stu) / 10);//得加括号
			stu++;
		}
		if(0 == t)
		{
			printf("stu:%d\n", stu - 1);
			printf("total:%d\n", total);
			break;
		}
		
	}

	return 0;
}
