#include<stdio.h>
#include<math.h>

int isPrime(int);

int main()
{
	int n, j, s;
	scanf("%d", &n);
	for (j = 1; j <= n; ++j)
	{
		scanf("%d", &s);
		if (isPrime(s))
		{
			printf("Case #%d:\n%d\n", j, s);
		}
		else
		{
			int r = 0;
			int A[200000];
			int mid = sqrt(s);
			for (int i = 2; i < mid+1;)
			{
				if (s%i == 0)
				{
					s = s / i;
					A[r++] = i;
				}//质因数分解
				else  ++i;

				if (s%i != 0)
				{
					A[r] = s;
				}
			}
			for (int i = 0; i < r; ++i)
			{
				if (A[i] == A[i + 1])
				{
					A[i] = 1;
					A[i + 1] = 1;
				}//两个相同质因数化为1（因为可成平方数）
			}
			int sum=1;
			for (int i = 0; i <= r; ++i)
			{
				sum *= A[i];
			}
			printf("Case #%d:\n%d\n", j, sum);
		}
	}
}

int isPrime(int a)
{
	int m;
	if (a == 1 || a == 2) return 1;
	if (a%2==0) return 0;
	if (a >= 3)
	{
		int mid = sqrt(a) + 1;
		for (m = 2; m < mid; ++m)
		{
			if (a%m == 0) return 0;
		}
	return 1;
	}
}
