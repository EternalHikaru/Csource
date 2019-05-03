/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
#define max 20001
#include<stdio.h>

int Scan(int A[])
{
	int i = 0;
	for (i = 0; i<max; ++i)
	{
		scanf("%d", &A[i]);
		char c=getchar();
		if (c == '\n') break;
		
	}
	return i;
}
int main()
{
	int A[max],B[max], size, i, j=0, k=1;
	size = Scan(A);
	for ( i=0; i <= size; ++i)
	{
		if (A[i] % 2 == 0){
			for (; j <= size;)
			{
				B[j] = A[i];
				j += 2;
				break;
			}
		}
		if (A[i] % 2 == 1){
			for (; k<=size;)
			{
				B[k] = A[i];
				k += 2;
				break;
			}
		}
	}
	for (i = 0; i<=size; ++i)
	{
		printf("%d ", B[i]);
	}

}