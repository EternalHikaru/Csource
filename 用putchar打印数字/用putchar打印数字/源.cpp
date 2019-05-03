#include<stdio.h>
#include<stdlib.h>
#define TS(r)  r<10?r+'0':r-10+'A'//把10~16转换为字母
void PT(int, int);

void PT(int a, int n)
{
	if (a < n) putchar(TS(a));
	else {
	  PT(a/n, n);//递归
	  putchar(TS(a%n));
	}
}

int main()
{
	int num,base;
	printf("转换内容：");
	scanf("%d", &num);
	printf("转换进制：");
	scanf("%d", &base);

	PT(num, base);

	system ("pause");
	return 0;
}

