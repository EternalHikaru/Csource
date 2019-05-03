#include<stdio.h>

int main()
{
	double a,b,r,A,B;
	printf("输入点（a,b)与圆半径和圆心(A,B)\n");
	scanf("%lf %lf %lf %lf %lf", &a, &b, &r, &A, &B);
	printf("点(%.2f,%.2f)在以(%.2f,%.2f)为圆心以%.2f为半径的圆%s\n",a,b,A,B,r,(a-A)*(a-A)+(b-B)*(b-B) <= r*r ? "内" : "外");
	return 0;
}