#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	scanf("%d", &a);
	b = a*6;
	
	printf("总共%.1f圆,要一元%d张 5角%d张 1角%d张", b/10.0,b/10,b%10/5,b%5);
	return 0;
}