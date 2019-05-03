#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if (x >= y) printf("MMM BRAINS\n");
		else printf("NO BRAINS\n");
	}
}