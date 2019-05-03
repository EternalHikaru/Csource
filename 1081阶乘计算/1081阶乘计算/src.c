#include<stdio.h>
#include<math.h>

int main()
{
	int n,num=0;
	int  result[10000] = { 0 };
	result[0] = 1;
	char RES[10000] = { '\0' };
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		
		for (int q=0; q < 5000; ++q)
		{
			result[q] = result[q] * i;
		}
		for (int p = 0; p < 5000;++p)
		{
			if (result[p] >= 10) 
			{
				result[p + 1] += result[p] / 10;
				result[p] = result[p] % 10;
				num = p + 1;
			}
		}
	}
	for (int i = 0; i <= num; i++)
	{
		RES[i] = result[i]+'0';
	}
	for (int j = num; j>=0; --j)
	{
		printf("%c", RES[j]);
	}
}