#include<stdio.h>
#include<stdlib.h>
void S(int a[],int);//都+
void m(int a[],int);//都*
void D(int a[],int);//都/
void R(int a[]);//倒序
void P(int a[]);//调换Y,Z

void S(int *a,int n)
{
	int k,i;
	scanf("%d", &k);
	getchar();
	for (int i = 0; i < n; ++i)
	{
		a[i] += k;
	}
}
void m(int *a,int n)
{
	int k;
	scanf("%d", &k);
	getchar();
	for (int i = 0; i < n; ++i)
	{
		a[i] = a[i]*k;
	}
}
void D(int *a,int n)
{
	int k;
	scanf("%d", &k);
	getchar();
	for (int i = 0; i < n; ++i)
	{
		a[i] =a[i]/k;
	}
}
void R(int *a,int n)
{
	int tmp;
	for (int i = 0; i <= (n-1)/2; ++i)
	{ 
		tmp=a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = tmp;
	}
}
void P(int *a)
{
	int Y, Z;
	scanf("%d %d", &Y, &Z);
	getchar();
	int tmp;
	tmp = a[Y];
	a[Y] = a[Z];
	a[Z] = tmp;
}

int main()
{
	int N, M,j=0;
	char *ch;
	int *a;
	scanf("%d %d", &N, &M);
	a = (int *)calloc(N, sizeof(int));
	ch = (char *)calloc(M, sizeof(char));

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &a[i]);
	}
	getchar();

	for (int i = 0; i < M; ++i)
	{
		scanf("%c", &ch[i]);
		getchar();
		if (ch[i]=='S')
		{
			S(a,N);
		}
		if (ch[i] == 'M')
		{
			m(a,N);
		}
		if (ch[i] == 'D')
		{
			D(a,N);
		}
		if (ch[i] == 'R')
		{
			R(a,N);
		}
		if (ch[i] == 'P')
		{
			P(a);
		}
		
	}
	for (int i = 0; i < N; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	free(a);
	free(ch);
	return 0;
}