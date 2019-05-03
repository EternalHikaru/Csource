#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b);


int compare(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int t;

	scanf("%d", &t);
	for (int p = 1; p <= t; p++)
	{
		int n;
		int x = 0, y = 0;
		int X
		scanf("%d", &n);
		int a[100001][2];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				scanf("%d", &a[i][j]);
			}
		}
		qsort(a[0], n, sizeof(int), compare);
		qsort(a[1], n, sizeof(int), compare);
		for (int i = 0; i < n; ++i)
		{
			if (a[i][0] != a[i + 1][0])	x++;
		}
		for (int j = 0; j < n; ++j)
		{
			if (a[j][1] != a[j + 1][1])	y++;
		}
		if (x <= 3 || y <= 3)
		{
			printf("Case #%d:\n1", p);
			break;
		}

	}
}