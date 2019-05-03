#include<stdio.h>
#include<stdlib.h>

void sort(int *,int n);
void swap(int *, int *);

int main()
{
	int n,*S;
	scanf("%d", &n);
	S = (int *)calloc(n, sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		S[i] = i + 1;
	}
	if (n == 0) printf("0");
	sort(S,n);
}

void sort(int *S, int n)
{

		int i, j,k;
	while (1)
		{
		for (i = 0; i < n; ++i)
		{
			printf("%d ", S[i]);
		}
		printf("\n");
		for (j = n - 2; j >= 0 && S[j] > S[j + 1]; j--);
		if (j < 0) return;
		for (k = n - 1; k>j && S[k] < S[j]; k--);
		swap(&S[k], &S[j]);
		for (int r = j + 1, q = n - 1; r < q; r++, q--)
		{
			swap(&S[r], &S[q]);
		}
	}
}

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}