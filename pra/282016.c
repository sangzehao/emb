#include <stdio.h>

int main(void)
{
	int num, weng, mu, chu;
	int money = 100;

	for (weng = 1; weng<99; weng++)
		for (mu = 1; mu < 99; mu++)
			for(chu = 3; chu < 99; chu += 3)
				if ( weng + mu + chu == 100 && weng * 5 + mu * 3 + chu * 1 / 3 == 100)
					printf("鸡瓮，鸡母，鸡雏数量分别为：%d, %d, %d\n", weng, mu, chu);

	return 0;
}
