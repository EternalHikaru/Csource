#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char fun[25] = { '\0' };
	while (scanf("%s", fun) != EOF)
	{
		int len = strlen(fun);
		char tmp[25] = { '\0' };
		int final[25] = { 0 };
		char TMP[25][25] = { '\0' };
		int tmpnum[25][7] = { 0 };
		int zeronum = 0;
		for (int i = 0; i < len; ++i)
		{
			if (fun[i] == 'B' || fun[i] == 'F' || fun[i] == 'P' || fun[i] == 'V')
			{
				tmp[i] = '1';
				continue;
			}
			if (fun[i] == 'C' || fun[i] == 'G' || fun[i] == 'J' || fun[i] == 'K' || fun[i] == 'Q' || fun[i] == 'S' || fun[i] == 'X' || fun[i] == 'Z')
			{
				tmp[i] = '2';
				continue;
			}
			if (fun[i] == 'D' || fun[i] == 'T')
			{
				tmp[i] = '3';
				continue;
			}
			if (fun[i] == 'L')
			{
				tmp[i] = '4';
				continue;
			}
			if (fun[i] == 'M' || fun[i] == 'N')
			{
				tmp[i] = '5';
				continue;
			}
			if (fun[i] == 'R')
			{
				tmp[i] = '6';
				continue;
			}
			else
			{
				tmp[i] = '0';
				zeronum++;
			}
		}
		if (zeronum > 0)
		{
			int r = 0, NUM = 0;
			for (int i = 0; i < len; i++)//²ð·Ö
			{
				if (tmp[r] == '0')
				{
					r++;
					continue;
				}
				for (int j = 0; j < len; ++j)
				{
					TMP[i][j] = tmp[r++];
					NUM++;
					if (tmp[r] == '0')
					{
						break;
					}
					if ((NUM + zeronum) == len) break;
				}
				if ((NUM + zeronum) == len) break;
			}
			for (int i = 0; i < len; ++i)
			{
				if (TMP[i][0] == '\0') continue;
				else
				{
					for (int j = 0; j < len; ++j)
					{
						if (TMP[i][j] == '0') continue;
						tmpnum[i][TMP[i][j] - '0']++;
						TMP[i][j] = '0';
					}
				}
			}
			for (int v = 0; v < len; ++v)
			{
				int bool1 = 0;
				for (int i = 0; i < len; ++i)
				{
					for (int j = 0; j < 7; ++j)
					{
						if (tmpnum[i][j] != 0)
						{
							final[v] = j;
							tmpnum[i][j] = 0;
							bool1 = 1;
							break;
						}
					}
					if (bool1)
					{
						bool1 = 0;
						break;
					}
				}
			}
		}
		else
		{
			int j = 0;
			for (int i = 0; i < len; ++i)
			{
				if (tmp[i] == tmp[i + 1])
				{
					continue;
				}
				else
				{
					final[j++] = tmp[i]-'0';
				}
			}
		}
		int iii = 0;
		while (final[iii] != 0)
		{
			printf("%d", final[iii]);
			iii++;
		}
		printf("\n");
	}
}
