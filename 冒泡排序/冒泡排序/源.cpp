#include<stdio.h>
void Reording(int array[], int size);
int  Readarray(int array[]);
#define max 9999

int Readarray(int array[])
{
	int i = 0;
	while (i<max)
	{
		scanf("%d", &array[i]);
		char c = getchar();
		if (c == '\n') break;
		++i;
	}
	return i;
}

void Reording(int array[], int size)//size为数据个数
{
	int tmp, i, j, time;
	for (i = 0; i < size; ++i)//单趟冒泡
	{
		time = 0;
		for (j = 0; j < size - i; ++j)//一趟冒泡中的数据排列
		if (array[j + 1] < array[j])
		{
			tmp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = tmp;
			++time;
		}
		if (!time) break;
	}
}

int main()
{
	int array[max], size,i;
	
	printf("要进行排序的数:\n");
	size = Readarray(array);
	Reording(array, size);
	for (i=0; i <= size; ++i)
	{
		printf("%d\t", array[i]);
	}
	return 0;
}