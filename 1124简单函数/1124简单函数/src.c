#include<stdio.h>
int main()
{
	double k, b;
	while (scanf("%lf %lf", &k,&b) != EOF)
	{
		if (k < 0) printf("Decreasing\n");
		if (k>0) printf("Increasing\n");
		if (k == 0) printf("Constant\n");
	}
}