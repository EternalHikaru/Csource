#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, m, S[30][30] = { 0 }, sum[30][30] = { 0 }, Sum[30][30] = { 0 }, i, j, k;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			scanf("%d", &S[i][j]);
		}
	}
	if (m == 0)
	{
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				if (i==j)
				sum[i][j] = 1;
			}
		}
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				printf("%d ", sum[i][j]);
			}
			printf("\n");
		}
		return 0;
	}
	
	if (m == 1)
	{
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				printf("%d ",S[i][j]);
			}
			printf("\n");
		}
		return 0;
	}
	
	else{
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				sum[i][j] = S[i][j];
			}
		}
		while (--m)
		{
			for (i = 0; i < n; ++i)
			{
				for (j = 0; j < n; ++j)
				{
					for (k = 0; k < n; ++k)
					{
						Sum[i][j] += sum[i][k] * S[k][j];
					}
				}
			}
			for (i = 0; i < n; ++i)
			{
				for (j = 0; j < n; ++j)
				{
					sum[i][j] = Sum[i][j];
					Sum[i][j] = 0;
				}
			}
		}
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				printf("%d ", sum[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}