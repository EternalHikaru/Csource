#include<stdio.h>

int main()
{
	int n;
	int h, min, s;
	scanf("%d", &n);
	h = n / 3600;
	min = (n - h * 3600) / 60;
	s = (n - h * 3600 - min * 60);
	printf("%d:%d:%d\n", h, min, s);
	return 0;
}