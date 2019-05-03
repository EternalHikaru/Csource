#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>



void main()
{
	int i = 0;
	char c;
	int *a = (int *)malloc(sizeof(int));
	int n;
	while (scanf("%d", &n))
	{
		*(a+i) = n;
		i++;
		a = (int *)realloc(a, (i + 1)*sizeof(int));//realloc¹Ø¼ü
		if ((c = getchar()) == '\n') break;
	}
	for (int j = 0; j < i; ++j)
	{
		printf("%d ",a[j]);
	}
	printf("\n");
	system("pause");
	return;
	
}