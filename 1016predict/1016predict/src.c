#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compare(const void*a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int Case;
	scanf("%d", &Case);
	for (int o = 0; o < Case;++o)
	{
		int p, r;
		scanf("%d %d", &p, &r);//p为猜球人数，r为球赛进行轮数
		getchar();
		char P[51][51] = { '\0' };
		char newP[51][51] = { '\0' };
		char newnewP[51][51] = { '\0' };
		int newmol[51] = { 0 };
		int mol[51] = { 0 };
		int MOL[51] = { 0 };
		int newnewmol[51] = { 0 };
		int Peo[51] = { 0 };
		int newPeo[51] = { 0 };
		int score[51] = { 0 };
		for (int i = 0; i < p; i++)
		{
			gets(P[i]);
		}
		int max = 0;
		while (r--)//r为轮数
		{
			int g;
			scanf("%d", &g);
			getchar();
			while (g--)//g为进行的比赛场数
			{
				char game[10] = { '\0' };
				gets(game);
				char peoplegame[51][10] = { '\0' };
				for (int j = 0; j < p;++j)
				{
					gets(peoplegame[j]);
				}
				int peopleresult[51] = { -1 };
				for (int m = 0; m < p; m++)
				{
					int result=-1;//0为平，1为赢，2为输；
					if (game[0] - '0'>game[4] - '0') result = 1;
					if (game[0] - '0' == game[4] - '0') result = 0;
					if (game[0] - '0' < game[4] - '0') result = 2;
					if (peoplegame[m][0] - '0'>peoplegame[m][4] - '0') peopleresult[m] = 1;
					if (peoplegame[m][0] - '0' == peoplegame[m][4] - '0') peopleresult[m] = 0;
					if (peoplegame[m][0] - '0' < peoplegame[m][4] - '0') peopleresult[m] = 2;
					if (peopleresult[m] == result)
					{
						Peo[m]++;
						score[m]++;
						if (peoplegame[m][0] == game[0] && peoplegame[m][4] == game[4])
						{
							Peo[m] += 2;
							score[m] += 2;
						}
					}
				}
			}
			for (int a = 0; a < p; ++a)
			{
				if (Peo[a]>max) max = Peo[a];
			}
			for (int f = 0; f < p; ++f)
			{
				if (score[f] == max)
				{
					mol[f]++;
				}
			}
		}
		
		qsort(Peo, p, sizeof(int), compare);
		for (int f = 0; f < p; ++f)
		{
			for (int x = 0; x < p; x++)
			{
				if (Peo[f] == score[x])
				{
					for (int q = 0; q < 51; ++q)
					{
						newP[f][q] = P[x][q];
					}
					newmol[f] = mol[x];
					MOL[f] = mol[x];
					score[x] = -1;
					break;
				}
			}
		}

		for (int i = 0; i < p; ++i)
		{
			int num = 1;
			if (Peo[i] == -1) continue;
			if (Peo[i] == Peo[i + 1])
			{
				num++;
				continue;
			}
			qsort(newmol, i+1, sizeof(int), compare);
			for (int w = 0; w <=i; w++)
			{
				if (Peo[w] == -1) continue;
				for (int y = 0; y <= i; ++y)
				{
					if (newmol[y] == -1) continue;
					for (int h = 0; h <= i; ++h)
					{
						if (MOL[h] == -1) continue;
						if (newmol[y] == MOL[h])
						{
							for (int v = 0; v < 51; ++v)
							{
								newnewP[w][v] = newP[h][v];
							}
							newnewmol[w] = MOL[h];
							newPeo[w] = Peo[w];
							MOL[h] = -1;
							newmol[y] = -1;
							Peo[w] = -1;
							break;
						}
					}
					break;
				}
			}
		}



		printf("Scenario #%d:\n", o+1);
		{
			for (int h = 0; h < p;++h)
			{
				printf("%d %d %s\n", newPeo[h], newnewmol[h],newnewP[h]);
				if (h == p - 1) printf("\n");
			}
		}

	}
}