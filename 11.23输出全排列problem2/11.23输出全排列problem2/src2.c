#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10000
int array[max];
void getnum(int *array, int now, int sum);

int main()
{
	int n;
	scanf("%d", &n);
	getnum(array, 0, n);
	return 0;
}

void getnum(int *array, int now, int sum)
{
	
	if (now == sum)
	{
		for (int i = 0; i < sum; ++i)
		{
			printf("%d ",array[i]);	
		}
		printf("\n");
	}
	else
	{
		for (int i = 1; i <= sum; ++i)
		{
			int bool0=1;
			for (int j = 0; j < now; ++j)
			{
				if (array[j] == i)
				bool0 = 0;
			}
			if (bool0)
			{
				array[now] = i;
				getnum(array, now + 1, sum);
			}
		}
	}
}