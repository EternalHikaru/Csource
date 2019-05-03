#include<stdio.h>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

int main()
{
	double x1, x2, x3, x4, y1, y2, y3, y4;
	double minX1, minY1, maxX1, maxY1, minX2, minY2, maxX2, maxY2;
	double m1, m2, n1, n2;
	double S;
	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	scanf("%lf %lf %lf %lf", &x3, &y3, &x4, &y4);
	maxX1 = max(x1, x2);
	maxX2 = max(x3, x4);
	minX1 = min(x1, x2);
	minX2 = min(x3, x4);
	maxY1 = max(y1, y2);
	maxY2 = max(y3, y4);
	minY1 = min(y1, y2);
	minY2 = min(y3, y4);
	m1 = min(maxX1, maxX2);
	m2 = max(minX1, minX2);
	n1 = min(maxY1, maxY2);
	n2 = max(minY1, minY2);
	if (m1>m2&&n1>n2)
	{
		S = (m1 - m2)*(n1 - n2);
		printf("%.2f\n", S);
	}
	else
	{
		S = 0;
		printf("%.2lf\n", S);
	}
	return 0;
}