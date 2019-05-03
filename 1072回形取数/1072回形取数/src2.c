#include<stdio.h>
int S[202][202] = { -1 };
//∆’Õ®∞Ê

int main()
{
	int n, k, i, j, sum;
	scanf("%d %d", &n, &k);
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
	return 0;
}