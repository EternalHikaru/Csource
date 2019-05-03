#include<stdio.h>
#include<stdlib.h>
int compare(const void *,const void *);


int main()
{
	int T;
	scanf("%d", &T);
	//getchar();
	while (T--)
	{
		int  n, i, j, x, y, k, m, l1,q, p,r,d;
		char face[102][102] = { '\0' };
		char FACE[102][102] = { '\0' };
		int alphabet[26] = { 0 };//字母表
		int ZMB[26] = { 0 };//字母表
		int bool1 = 0, bool2 = 0, bool3 = 0,bool4=0;
		scanf("%d", &n);
		//getchar();
		//输入
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				scanf("%c", &face[i][j]);
				if (face[i][j]>'Z'||face[i][j]<'A') scanf("%c", &face[i][j]);
				FACE[i][j] = face[i][j];
			}
		}
		//特殊情况：只有一个字母
		if (n == 1)
		{
			bool4 = 1;
		}
		if (bool4)
		{
			int a = 1;
			int b = 1;
			printf("%d %d\n",a,b);
		}
		//字母出现次数桶排序
		for (k = 0; k < n; ++k)
		{
			for (m = 0; m < n; ++m)
			{
				if (face[k][m] <= 'Z'&&face[k][m] >= 'A')
				{
					alphabet[face[k][m] - 'A']++;
					ZMB[face[k][m] - 'A']++;
				}
			}
		}
		//快速排序
		qsort(alphabet, 26, sizeof(int), compare);
		//出现大于等于两个的单个字母
		for (r = 0; r < 26; ++r)
		{
			if (alphabet[r] ==1&& alphabet[r + 1]==1)
			bool3 = 1;
		}
		if (bool3)
		{
			printf("Undeterminable!\n");
		}
		//
		for (d = 1; d<25; ++d)
		{
			if ((alphabet[d] == 1 && alphabet[d + 1]>1 && alphabet[d - 1] < 1) || (alphabet[0] == 1 && alphabet[1]>1))
			{
				bool1 = 1;
				break;
			}
		}
		for (q = 0; q < n; ++q)
		{
			for (p = 0; p < n; ++p)
			{
				if (ZMB[FACE[q][p] - 'A'] == 1)
				{
					x = q;
					y = p;
					break;
				}
			}
			if (ZMB[FACE[q][p] - 'A'] == 1) break;
		}
		if (bool1)
		{
			printf("%d %d\n", x + 1, y + 1);
			x = 0;
			y = 0;
		}
	
		for (l1 = 0; l1 < 26;++l1)
		{
			if (alphabet[l1] == 0 && alphabet[l1 + 1]>1)
			{
				bool2 = 1;
				break;
			}
		}
		if (bool2)
		{
			printf("Wenjun is not here!\n");
		}
	}
}

int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}