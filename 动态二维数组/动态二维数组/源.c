#include<stdio.h>
#include<stdlib.h>

int main()
{
	int row, clo, i, j,**a;
	printf("要创建二维数组的行数与列数为：\n");
	scanf("%d %d", &row, &clo);
	a = (int **)calloc(row, sizeof(int *));//指向指针的指针（每一行首地址）注意整形指针大小表示方式为sizeof(int *)
	for (i = 0; i < row; ++i)
	{
		a[i] = (int *)calloc(clo, sizeof(int));//为每一行分配空间
	}
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < clo; ++j)
		{
			printf("a[%d][%d]=", i+1, j+1);//这里+1仅为了习惯行列式从1行1列开始
			scanf("%d", &a[i][j]);
		}
	}
	printf("\n");
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < clo; ++j)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < row; ++i)
		free(a[i]);//释放每一行空间
	free(a);//释放每一行首地址空间，即总空间
	system("pause");
	return 0;
}