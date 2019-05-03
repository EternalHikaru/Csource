#include<stdio.h>
#include<stdlib.h>
int compare(const void*a, const void*b);

int main()
{
	int n, S[10] = { 0 }, p[10] = { 0 }, i,j,sum=0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &p[i]);
		char ch;
		ch = getchar();
		if ('ch' == '\n') break;
	}
	qsort(p, n, sizeof(int), compare);
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j <= i;++j)
		S[i] += p[j];
	}
	for (i = 0; i < 10; ++i)
	{
		sum += S[i];
	}
	printf("%d\n", sum);
	
}
int compare(const void*a, const void*b)
{
	return *(int *)a - *(int *)b;
}