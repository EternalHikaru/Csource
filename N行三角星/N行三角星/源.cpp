#include <stdio.h>

int main()
{
	int n, i, j;;

	printf("������������");
	scanf("%d", &n);

	for (i = 1; i <= n; ++i) {
		for (j = 0; j <= n - i; ++j)/*��n-1��Ϊ�ո��������һ����������*/
			putchar(' ');
		for (j = 0; j <2 * i - 1; ++j)/*��2i-1��Ϊ*��ÿһ���������پ������ҹ�ϵΪ*��=��2*����-1��*/
			putchar('*');
		putchar('\n');
	}
	return 0;
}
