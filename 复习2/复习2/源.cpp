#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, j,n;
	scanf("%d", &n);
	int *a;
	a = (int *)calloc(n, sizeof(int));
	a[0] = 1;
	for (i = 1; i <= n; ++i)
	{
		a[i-1] = 1;
		for (j = i-2; j>0; --j)
		{
			a[j] += a[j - 1];
		}
		for (j = i-1; j <= n; ++j)
		{
			putchar(' ');
		}
		for (j = 0; j < i; ++j)
		{
			printf("%d ", a[j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}