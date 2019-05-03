#include<stdio.h>
#include<stdlib.h>
void Hanoi(int n, char start, char temp, char finish);
int  times(int n);
int i;
//��A���ƶ���C��,tempΪ��ʱ������������
//��������ΪA��B��C��A���ϵ�����n����С���ȵ��̣����ε���Ϊ�������£�С�����¡�
//Ҫ�����n�����Ƶ�C���ϣ����ƶ������п��Խ���B��
//1��ÿ��ֻ����һ����
//2�����ƶ������б��뱣��3�����ϵĴ������£�С������
//3������ֻ����3�����Ӽ��ƶ������ܷ�������

void Hanoi(int n, char start, char temp, char finish)
//�ݹ�ʱ����˳��,ʹ�ƶ������Ϊstart->finish   
{
	if (n == 1){
		printf("%c->%c\t", start, finish);
	}
	else 
	{
		Hanoi(n - 1, start/*A*/, finish/*B*/, temp/*C*/);//��A�ϣ�n-1�������Ӵ�A����C�ƶ���B
		printf("%c->%c\t", start/*A*/, finish/*C*/);//��Aʣ�µ�����������A�Ƶ�C
		Hanoi(n - 1, temp/*A*/, start/*B*/, finish/*C*/);//���Ƶ�B��(n-1)�����Ӵ�B����A�Ƶ�C
	}
}

int times(int)//����������2^n-1,nΪ����)
{
	int n = 1,S=1,r=1;
	for (r; r < i; ++r){
		n *= 2;
		S += n;
	}
	return S;
}

int main()
{
	printf("�ܹ��м������ӣ�\n");
	scanf("%d", &i);
	Hanoi(i, 'A', 'B', 'C');//�����'A','B','C'������Hanoi���������Ķ�Ӧ
	printf("�ƶ�������%d\n", times(i));
	system ("pause");
	return 0;
}