#include<stdio.h>
#define max 10002//排序数数目+1
#define arraymax 401//排序数中最大数+1
void sort(int array[],int size);
int REmove(int array[], int size);


int main()
{
	int n, array[max], i;	
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &array[i]);
		}
		sort(array,n);
		putchar(' ');
	}
	return 0;
} 

void sort(int array[],int size)//桶排序
{
	int S[arraymax] = { 0 }, i;
	for (i = 0; i < size; ++i)
	{
		S[array[i]]++;
	}
	for (i = 0; i <arraymax ; ++i)
	{
		if (S[i] != 0) {
			printf("%d ", i);
		}
	}
}
