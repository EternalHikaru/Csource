#include<stdio.h>

int main()
{
	int a, b;
	int *p1=&a, *p2=&b;
	scanf("%d %d", &a, &b);
	*p1 = a;
	*p2 = b;
	printf("%d %d", *p1, *p2);
}