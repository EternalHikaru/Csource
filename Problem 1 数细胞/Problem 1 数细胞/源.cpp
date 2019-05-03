#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void findcell(char array[1002][1002],int ,int);
int n;


int main()
{
	int SUM = 0;
	char array[1002][1002];
	scanf("%d", &n);
	getchar();
	memset(array, 0, sizeof(array));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%c", &array[i][j]);
			if (array[i][j] == '\n')
			{
				scanf("%c", &array[i][j]);
			}
		}
	}
	for (int p = 1; p <= n; p++)
	{
		for (int q = 1; q <= n; q++)
		{
			if (array[p][q] == '#')
			{
				findcell(array,p, q);
				SUM++;
			}
		}
	}
	printf("%d\n", SUM);

}

void findcell(char array[1002][1002],int x,int y)
{
	int i = 0;
	int sum=0;
	array[x][y] = '.';
	if (array[x + 1][y] != '#'&&array[x][y + 1] != '#'&&array[x - 1][y] != '#'&&array[x][y - 1] != '#')
	{
		return;
	}
	else
	{
		if (array[x + 1][y] == '#')
		{
			findcell(array, x + 1, y);
		}
		if (array[x][y + 1] == '#')
		{
			findcell(array, x, y + 1);
		}
		if (array[x - 1][y] == '#')
		{
			findcell(array, x - 1, y);
		}
		if (array[x][y - 1] == '#')
		{
			findcell(array, x, y - 1);
		}
	}
}