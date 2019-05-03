#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void Goldbach(int, int *, int *);
int isPrime(double);

void Goldbach(int a, int *p1, int *p2)
{
	int i;
	if (a == 4){
		*p1 = 2;
		*p2 = 2;
	}
	for (i = 3; i < a; i += 2)
	{
		if (isPrime(double(i)) && isPrime(double(a - i))){
			*p2 = a - i;
			*p1 = i;
			break;
		}
	}
	printf("%d=%d+%d\n", a, *p1, *p2);
}

int isPrime(double a)
{
	int i,max=sqrt(a)+1;
	for(i = 3; i < max; i += 2)
	if (int(a)%i == 0) return 0;
	return 1;
}

int main()
{
	int a, p1, p2,t;
	scanf("%d", &t);
	for (a = 4; a <= t; a+=2)
		Goldbach(a, &p1, &p2);
	system("pause");
	return 0;
}