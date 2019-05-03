#include<stdio.h>

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	int z = x;
	x = y;
	y = z;
	printf("%d %d", x, y);
}