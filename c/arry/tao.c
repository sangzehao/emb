#include<stdio.h>
#include<string.h>

int main(void)
{
	int row, column, len, i, j, pos;

	char arr[100];

	fgets(arr, 100, stdin);
	puts(arr);
	printf("row:");
	scanf("%d", &row);
	len = strlen(arr) - 1;
	printf("len:%d\n", len);

	if(len % row)
		column = len / row + 1;
	else
		column = len / row;
	printf("column:%d\n", column);
	
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			int pos = (column - j -1) * row + i;
			if(pos < len)
				printf("%c", arr[(column - j - 1) * row + i] );
			else
				printf(" ");
		}

		printf("\n");
	}

	return 0;
}
