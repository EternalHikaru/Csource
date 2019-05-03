#include<stdio.h>
#include<stdlib.h>


int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	while (1)
	{
		int num;
		int NUM[5001] = { 0 };
		long long sum=0;
		scanf("%d", &num);
		if (num == 0) break;
		for (int i = 0; i < num;++i)
		{
			scanf("%d", &NUM[i]);
		}
		qsort(NUM, num, sizeof(int), compare);
		for (int i = 0; i < num; ++i)
		{
			sum += NUM[i];
		}
		if (num % 2 != 0)
		{
			printf("No\n");
		}
		if (num % 2 == 0)
		{
			if (sum % (num / 2) != 0) printf("No\n");
			else
			{
				int tmp = sum / (num / 2);
				int bool1 = 1;
				for (int j = 0; j < (num / 2); j++)
				{
					if (NUM[j] + NUM[num - j - 1] != tmp)
					{
						bool1 = 0;
						break;
					}
				}
				if (bool1) printf("Yes\n");
				if (!bool1) printf("No\n");
			}
		}
	}
}