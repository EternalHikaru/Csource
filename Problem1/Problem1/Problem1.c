#include<stdio.h>
int main()
{
	unsigned long long int a,b,s,c,A,B;

	scanf("%llu %llu", &a, &b);
	A = a;
	B = b;

	if (a > b);
	else {
		c = a;
		a = b;
		b = c;
	}//保证a大于b

	s = a%b;
	while (s)
	{
		a = b;
		b = s;
		s = a%b;
	}
	c = (A / b)*B;

	printf("%llu\n", b);
	printf("%llu\n", c);
	
	return 0;

}