#include <stdio.h>
#include <stdlib.h>

int array[2][2];

int main()
{
	array[0][0] = 0;
	array[0][1] = 1;
	array[1][0] = 0;
	array[1][1] = 0;
	printf("��A^2=O,��A��һ��=O(O��0����)  eg:\n%3d%3d\n%3d%3d\n", array[0][0], array[0][1], array[1][0], array[1][1]);
	system("pause");
	return 0;
}