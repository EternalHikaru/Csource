#include <stdio.h>

int main()
{
	int n, i, j;;

	printf("请输入行数：");
	scanf("%d", &n);

	for (i = 1; i <= n; ++i) {
		for (j = 0; j <= n - i; ++j)/*用n-1因为空格数由最后一行行数决定*/
			putchar(' ');
		for (j = 0; j <2 * i - 1; ++j)/*用2i-1因为*由每一行行数多少决定，且关系为*数=（2*行数-1）*/
			putchar('*');
		putchar('\n');
	}
	return 0;
}
