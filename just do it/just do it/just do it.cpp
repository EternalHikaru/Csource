#include<stdio.h>


int main()
{
	double n,m,A;
	
	scanf("%lf %lf",&n,&m);

	A=m*(4*(((m-1)*(m-2))/2)*3)+m*(4*((m*(m-1))/2)*(n-m+1));
	printf("%.0f",A);
	return 0;
}
