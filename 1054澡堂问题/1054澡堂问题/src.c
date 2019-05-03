#include<stdio.h>

int main()
{
	int N, M;
	double p;
	scanf("%d %d", &N, &M);
	if (M == 0) p = 1;
	if (N > M)
	{
		p = 1 - (M*1.0) / N;
		printf("%.3f\n", p);
	}
	if (N <= M)
	{
		p = 0;
		printf("%.3f", p);
	}
	return 0;
}