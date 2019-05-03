#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//动态数组版

int main()
{
	int n, k, i, j, sum;
	int **S;
	scanf("%d %d", &n, &k);//先行后列
	S = (int **)calloc(n, sizeof(int *));
	for (i = 0; i < k; ++i)
	{
		S[i] = (int *)calloc(k, sizeof(int));
	}
	sum = n*k;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < k; ++j)
		{
			scanf("%d", &S[i][j]);
		}
	}
	int a = 0, b = 0, num = 0;
	while (num < sum){
		while (a<n&&S[a][b] != -1)
		{
			printf("%d ", S[a][b]);
			S[a][b] = -1;
			++num;
			a++;
		}
		a--;
		b++;
		while (b<k && S[a][b] != -1)
		{
			printf("%d ", S[a][b]);
			S[a][b] = -1;
			++num;
			b++;
		}
		b--;
		a--;
		while (a >= 0 && S[a][b] != -1)
		{
			printf("%d ", S[a][b]);
			S[a][b] = -1;
			a--;
			++num;
		}
		a++;
		b--;
		while (b >= 0 && S[a][b] != -1)
		{
			printf("%d ", S[a][b]);
			S[a][b] = -1;
			++num;
			b--;
		}
		b++;
		a++;
		if (num == sum) break;
	}
	for (int i = 0; i < k; ++i)
	{
		free(S[i]);
	}
	free(S);
	printf("\n");
	return 0;
}