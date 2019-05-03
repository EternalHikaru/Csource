#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX 10
int Scan(int size, int array[]);
void Reverse(int size, int i, int array[]);
void print(int size, int array[]);

int Scan(int max,int End, int array[])
{
	int size = 0;
	printf("输入数组且以%d结束：",End);
	while (size<max){
		scanf("%d", &array[size]);
		if (array[size] == End) break;
		else ++size;
	}
	return size;
}

void Reverse(int size,int array[])
{
	int i = 0,tmp;
	for (; i < size / 2; ++i){
		tmp = array[i];
		array[i] = array[size - i - 1];
		array[size - 1 - i] = tmp;
	}
}

void print(int size, int array[])
{
	int i =0 ;
	if (size == 0) return;
	printf("逆序为:\n");
	for ( ; i < size; ++i)
	{
		printf("%d\t", array[i]);
	}
}

int main()
{
	int array[MAX], End,size;
	printf("结束标志：");
	scanf("%d", &End);
	size = Scan(MAX, End, array);
	Reverse(size,array);
	print(size,array);

	return 0;
}