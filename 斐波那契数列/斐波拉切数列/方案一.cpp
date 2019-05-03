#include <stdio.h>

int main()
{
	double n, F0 = 0, F1 = 1, F;
	int i;
	printf("斐波拉切数列项数:\t");
	scanf("%lf", &n);
	printf("F0=0\n");
	printf("F1=1\n");
	for (i = 2; i <= n; ++i){
		F = F0 + F1;
		printf("F%d=%.0f\n", i, F);
		F0 = F1; F1 = F;
	}
	return 0;
}