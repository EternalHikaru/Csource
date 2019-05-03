
#include<stdio.h>
#include<math.h>

int main()
{
	double a, b, c, S, f;
	printf("请输入三角形的任意三边：a b c\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	f = (a + b + c) / 2;
	S = sqrt(f*(f - a)*(f - b)*(f - c));
	printf("S=%f", S);
	return 0;
}