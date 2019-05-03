#include<stdio.h>
#include<stdlib.h>


int main()
{
	int *Y, i, j,row;
	printf("所要打印的行数：\n");
	scanf("%d", &row);
	Y = (int *)calloc(row, sizeof(int));
	Y[0] = 1;
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < row - i; ++j)
		{
			putchar(' ');
		}
		for (j = 0; j <= i; ++j)
		{
			printf("%d ", Y[j]);
		}
		printf("\n");
		Y[i + 1] = 1;
		for (j = i; j>0; --j)
		{
			Y[j] += Y[j - 1];
		}
	}
	system("pause");
	return 0;
}