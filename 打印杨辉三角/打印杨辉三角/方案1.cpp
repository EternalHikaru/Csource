#include<stdio.h>
#include<stdlib.h>
#define max 100
//��״������Ϊ8���ڿ��Խ���


int main()
{
	int Y[max][max], i, j, row;
	printf("��Ҫ��ӡ��������\n");
	scanf("%d", &row);
	for (i = 0; i < row; ++i)
	{
		Y[i][0] = 1;
		for (j = 1; j < i; ++j)
		{
			Y[i][j] = Y[i - 1][j - 1] + Y[i - 1][j];
		}
		Y[i][i] = 1;
	}
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < row - i; ++j)
		{
			putchar(' ');
		}
		for (j = 0; j <= i; ++j)
		{
			printf("%d ", Y[i][j]);
		}

		printf("\n");
	}
	system("pause");
	return 0;
}