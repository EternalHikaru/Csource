
#include <stdlib.h>

#include <stdio.h>
int main(void)
{
	int number = 10;
	char string[25];
	itoa(number, string, 2);
	printf("ʮ��������%d������������%s\n", number, string);
	return 0;
}
