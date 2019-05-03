#include<stdio.h>
#include<math.h>
void Goldbach(int, int *, int *);
int isPrime(double n);

void Goldbach(int n, int *p1, int *p2)
{
	int a;
	if (n == 4){ *p1 = 2; *p2 = 2; }
	for (a = 3; a<n; a += 2){
		if (isPrime(a) && isPrime(n - a)){
			*p1 = a;
			*p2 = n - a;
			break;
		}
	}
	printf("%d=%d+%d\n", n, *p1, *p2);
}
int isPrime(double n)
{
	int i, max = sqrt(n) + 1;
	for (i = 3; i <= max; ++i){
		if (int(n) % i == 0) return 0;
	}
	return 1;
}
int main()
{
	int n, p1, p2, i;
	scanf("%d", &n);
	for (i = 4; i <= n; i += 2)
	{
		Goldbach(i, &p1, &p2);
	}
	return 0;
}