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

void Reording(int array[], int size)//sizeΪ���ݸ���
{
	int tmp, i, j, time;
	for (i = 0; i < size; ++i)//����ð��
	{
		time = 0;
		for (j = 0; j < size - i; ++j)//һ��ð���е���������
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
	
	printf("Ҫ�����������:\n");
	size = Readarray(array);
	Reording(array, size);
	for (i=0; i <= size; ++i)
	{
		printf("%d\t", array[i]);
	}
	return 0;
}