#include<stdio.h>
#include<stdlib.h>
#define TS(r)  r<10?r+'0':r-10+'A'//��10~16ת��Ϊ��ĸ
void PT(int, int);

void PT(int a, int n)
{
	if (a < n) putchar(TS(a));
	else {
	  PT(a/n, n);//�ݹ�
	  putchar(TS(a%n));
	}
}

int main()
{
	int num,base;
	printf("ת�����ݣ�");
	scanf("%d", &num);
	printf("ת�����ƣ�");
	scanf("%d", &base);

	PT(num, base);

	system ("pause");
	return 0;
}

