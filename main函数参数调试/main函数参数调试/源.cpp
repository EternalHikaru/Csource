#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Convert(char *);

int main(int agrc, char *agrv[])
{
	int i, sum = 0;
	double average,variance=0,Standvariance;
	for (i = 1; i < agrc; ++i)
	{
		sum += Convert(agrv[i]);
	}
	average = (sum*1.0) / (agrc-1);
	for (i = 1; i < agrc; ++i)
	{
		variance += (average - Convert(agrv[i]))*(average - Convert(agrv[i]));
	}
	variance = variance / (agrc-1);
	Standvariance = sqrt(variance);
	printf("平均值:%f\n方差:%f\n标准差:%f\n", average, variance, Standvariance);
	return 0;
}

int Convert(char *s)
{
	int sum=0;
	while (*s)
	{
		sum = sum*10+(*s-'0');
		++s;
	}
	return sum;
}