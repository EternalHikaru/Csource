#include<stdio.h>

int main()
{
	double x=0, *p;
	p = &x;
	printf("%d", sizeof(p));

}