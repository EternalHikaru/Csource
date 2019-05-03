#include<stdio.h>
#include<stdlib.h>

int main()
{
	int r, c;
	int **array;
	scanf("%d %d", &r, &c);
	array = (int **)calloc(r, sizeof(int *));
	for (int i = 0; i < r; i++)
	{
		array[i] = (int *)calloc(c, sizeof(int));
	}
	for (int j = 0; j < r; j++)
	{
		for (int p = 0; p < c; p++)
		{
			scanf("%d",&array[j][p]);
		}
	}
	if (r != c) { printf("NO\n"); return 0; }
	int bool1 = 1, bool2 = 1;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j<c; j++)
		{
			if (i == j)
			{
				if (array[i][j] != 1) bool1 = 0;
			}
			if (i != j)
			{
				if (array[i][j] != 0) bool2 = 0;
			}
		}
	}
	if (bool1&&bool2) printf("YES\n");
	if(!bool1||!bool2) printf("NO\n");
	for (int i = 0; i < r; i++)
	{
		free(array[i]);
	}
	free(array);
	return 0;
}