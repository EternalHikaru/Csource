#include<stdio.h>

int main()
{
	double a,b,r,A,B;
	printf("����㣨a,b)��Բ�뾶��Բ��(A,B)\n");
	scanf("%lf %lf %lf %lf %lf", &a, &b, &r, &A, &B);
	printf("��(%.2f,%.2f)����(%.2f,%.2f)ΪԲ����%.2fΪ�뾶��Բ%s\n",a,b,A,B,r,(a-A)*(a-A)+(b-B)*(b-B) <= r*r ? "��" : "��");
	return 0;
}