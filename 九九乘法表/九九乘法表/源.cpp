#include <stdio.h>
//�����Ǿžų˷���
int main()
{
	int i, j;

	printf("*\t1\t2\t3\t4\t5\t6\t7\t8\t9\n");
	for (i = 1; i <= 9; ++i) {
		printf("%d\t", i);
		for (j = 1; j < i; ++j)
			putchar('\t');
		for (j = i; j <= 9; ++j)
			printf("%d\t", i * j);
		putchar('\n');
	}

	return main();
}

#include<stdio.h>
//ȫ�žų˷���
int main()
{
	int i, j;

	printf("*\t1\t2\t3\t4\t5\t6\t7\t8\t9\n");
	for (i = 1; i <= 9; ++i) {
		printf("%d\t", i);
		for (j = 1; j <= 9; ++j)
			printf("%d\t", j*i);
		putchar('\n');
	}

	return 0;

}