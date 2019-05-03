#include<stdio.h>

int main()
{
	int l, w;
	while ((scanf("%d%d", &l, &w)) != EOF)
	{
		int bool0=1;
		int array[17][17] = { 0 };
		if (((w*l) - 2) % 2 == 1)
		{
			printf("My God!\n");
			continue;
		}
		else
		{
			for (int i = 1; i <= w; ++i)
			{
				for (int j = 1; j <= l; ++j)
				{
					array[i][j] = 1;
				}
			}
			array[1][1] = 0;
			array[w][l] = 0;
			for (int i = 1; i <= w; ++i)
			{
				for (int j = 1; j <= l; ++j)
				{
					if (array[i][j] == 1)
					{
						if (array[i][j+1] == 1)
						{
							array[i][j] = 0;
							array[i][j+1] = 0;
							continue;
						}
						if (array[i + 1][j] == 1)
						{
							array[i][j] = 0;
							array[i + 1][j] = 0;
							continue;
						}
						
					}
				}
			}
			for (int i = 1; i <= w; ++i)
			{
				for (int j = 1; j <= l; ++j)
				{
					if (array[i][j] == 1)
						bool0 = 0;
				}
			}
			if (bool0 == 0) printf("My God!\n");
			if (bool0 == 1) printf("God save the pig!\n");
		}
	}
}