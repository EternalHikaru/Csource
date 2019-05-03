#include<stdio.h>
#define maxrule_num 30
#include<math.h>

int main()
{
	char num[33] = { '\0' };
	int k,sum=0,trans=0;
	int rule[maxrule_num][2] = { -1 };
	int numtable[10] = { 0 };//记录数字出现次数
	int numtrans[10] = { 0 };
	scanf("%s %d", num, &k);
	for (int i = 0; i < k;i++)
	{
		scanf("%d %d", &rule[i][0], &rule[i][1]);
	}
	for (int i = 0; i < 33; i++)
	{
		if (num[i] != '\0')
		{
			numtable[num[i] - '0']++;
		}
	}
	for (int p = 0; p < k; ++p)
	{
		if (rule[p][0] != rule[p][1])
		{
			numtrans[rule[p][0]]++;
		}
	}
	for (int m = 0; m < 10; ++m)
	{
		if (numtrans[m] == 0) numtrans[m] = -1;
	}
	for (int j = 0; j < 10; j++)
	{
		if (numtable[j] != 0)
		{
			sum += (numtrans[j] + 1)*(numtable[j] * numtable[j]);
		}
	}
	printf("%d", sum);

}