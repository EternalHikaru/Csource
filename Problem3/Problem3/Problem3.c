#include<stdio.h>
#define max 101
char step;

int main()
{
	int N, M,i,j,a,b,A,B;
	scanf("%d %d", &N, &M);
	getchar();
	char map[max][max] = { '\0' };
	
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < M; ++j)
		{
			scanf("%c", &map[i][j]);
			if (map[i][j] == '\n') scanf("%c", &map[i][j]);
			if (map[i][j] == 'S')
			{
				a = i;
				A = i;
				b = j;
				B = j;
			}
		}
	}
	getchar();
	while (scanf("%c", &step)!=EOF)
	{
		getchar();
		if (step == 'E') b++;
		if (step == 'W') b--;
		if (step == 'S') a++;
		if (step == 'N') a--;
		if (map[a][b] == '.'){
			map[a][b] = 'S';
			map[A][B] = '.';
			A = a;
			B = b;
		}
		if (map[a][b] != '.'){
			a = A;
			b = B;
		}
			for (i = 0; i < N; ++i)
			{
				for (j = 0; j < M; ++j)
				{
					printf("%c", map[i][j]);
				}
				printf("\n");
			}
			printf("\n");
	}
	return 0;
}