#include<stdio.h>
#include<stdlib.h>
int Readarray(int array[]);
void Reording(int array[], int size);
void Print(int array[], int size);
#define MAX 9999

int Readarray(int array[])
{
	int i=0;
	while (i < MAX)
	{
		scanf("%d", &array[i]);
		char c = getchar();
		if (c == '\n') break;
		else ++i;
	}
	return i;
}

void Reording(int array[], int size)
{
	int lh, k, min, tmp;
	for (lh = 0; lh <= size; ++lh)
	{
		min = lh;
		for (k = min; k <= size; ++k)
		{
			if (array[k] < array[min]) min = k;
		}
		tmp = array[lh];
		array[lh] = array[min];
		array[min] = tmp;
	}
}

void Print(int array[], int size)
{
	int i;
	for (i = 0; i <= size; ++i)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
}

int main()
{
	int array[MAX],size;
	printf("请输入要排序的数：\n");
	size=Readarray(array);
	Reording(array, size);
	Print(array, size);
	system("pause");
	return 0;
}