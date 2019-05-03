#include<stdio.h>
//µİ¹é½â·¨
int F(int);

int F(int n){
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else if (n > 1)  return (F(n - 1) + F(n - 2)); 
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", F(n));
	return 0;
}