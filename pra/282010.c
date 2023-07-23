#include <stdio.h>

int main (void)
{
	int num1, num2, num3;
	int mid;

	printf("输入三个整数：");
	scanf("%d%d%d", &num1, &num2, &num3);
/*	if(num1 > num2){第一种方法调换位置，繁琐
		if (num3 > num1){
			printf("由大到小为：%d %d %d\n", num3, num1, num2);
		}else{
			if(num3 > num2)
				printf("由大到小为：%d %d %d\n", num1, num3, num2);
			else{
				printf("由小到大为：%d %d %d\n", num1, num2, num3);
			}
		}
	}else{
		if (num3 > num2){
			printf("由大到小为：%d %d %d\n", num3, num2, num1);
		}else{
			if(num3 > num1)
				printf("由大到小为：%d %d %d\n", num2, num3, num1);
			else{
				printf("由小到大为：%d %d %d\n", num2, num1, num3);
			}
		}
	}
	*/
	//第二种方法，借用一个中间量，交换值，把小的放前边，大的放后边，最终就是输出num1,num2, num3,顺序不变。更简单，简洁
	if (num1 > num2){
		mid = num1 ;
		num1 = num2;
		num2 = mid;
	}
	if (num1 > num3){
		mid = num1;
		num1 = num3;
		num3 = mid;
	}
	if(num2 > num3){
		mid = num2;
		num2 = num3;
		num3 = mid;
	}
	printf("从小到大顺序为：%d %d %d\n", num1, num2, num3);

	return 0;
}
