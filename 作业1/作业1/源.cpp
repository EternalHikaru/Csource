#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	scanf("%d", &a);
	b = a*6;
	
	printf("�ܹ�%.1fԲ,ҪһԪ%d�� 5��%d�� 1��%d��", b/10.0,b/10,b%10/5,b%5);
	return 0;
}