#include<stdio.h>
#define max 100

int main()
{
	int A[max][max], B[max][max], C[max][max], RofA, CofA, RofB, CofB,i,j,k;
	printf("矩阵A的行数,列数,矩阵B的行数,列数\n");
	scanf("%d %d %d %d", &RofA, &CofA, &RofB, &CofB);
	if (CofA != RofB) return 0;
	
	printf("\n输入A：\n");
	for (i = 1; i <=RofA; ++i)
	{
		for (j = 1; j <= CofA; ++j)
		{
			printf("A[%d][%d]=", i, j);
			scanf("%d", &A[i][j]);
		}
	}

	printf("\n输入B：\n");
	for (i = 1; i <= RofB; ++i)
	{
		for (j = 1; j <= CofB; ++j)
		{
			printf("B[%d][%d]=", i, j);
			scanf("%d", &B[i][j]);
		}
	}
	
	for (i = 1; i <= RofA; ++i)
	{
		for (j = 1; j <= CofB; ++j)
		{
			C[i][j] = 0;
			for (k = 1; k <= CofA; ++k)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	
	printf("\nC为：\n");
	for (i = 1; i <= RofA; ++i)
	{
		printf("\n");
		for (j = 1; j <= CofB; ++j)
		{
			printf("%d\t", C[i][j]);
		}
	}
	printf("\n");
	printf("\n");
	printf("\n");
	return main();
}