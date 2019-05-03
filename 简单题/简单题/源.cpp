#include<stdio.h>
#define max(a,b) a>b?a:b
#define MAX 1005
int Scan(char array[]);
int ABS(char A[], char B[], int size);


int Scan(char array[])
{
	int i=0;
	while (i<MAX)
	{
		scanf("%c", &array[i]);
		if (array[i]==' ') break;
		else ++i;
	}
	return i;//调用函数返回值为数组大小
}

int ABS(char A[], char B[], int size)
{
	int i,S=0;
	for (i = 0; i <= size; ++i)
	{
		if (A[i]>B[i]) S += A[i] - B[i];
		else S += B[i] - A[i];
	}
	return S;
}

int main()
{
	int K, n, j,i,a, b, S,size;
	scanf("%d", &n);
	getchar();

	while (n)
	{
		char A[MAX] = { '0' }, B[MAX] = { '0' }, C[MAX] = { '0' }, D[MAX] = { '0' };
		a = Scan(A)-1;
		b = Scan(B)-1;
		size = max(a, b);
		scanf("%d",&K);
		if (a > b){
			j = 0;
			do
			{
				C[a - b + j] = B[j];
				++j;
			} while (j != (b+1));

			i = 0;
			do
			{
				C[i] = '0';
				++i;
			} while (i != (a-b));
			S = ABS(A, C, size);
		}
		if (a < b){
			j = 0;
			do
			{
				D[b - a + j] = A[j];
				++j;
			} while (j != (a+1));

			i = 0;
			do
			{
				D[i] = '0';
				++i;
			} while (i != (b - a));
			S = ABS(B, D, size);
		}
		if (a == b) S = ABS(A, B, size);
		getchar();
		if (S < K) printf("yes\n");
		else if (S >= K) printf("no\n");
		--n;
	}

	return 0;
}
