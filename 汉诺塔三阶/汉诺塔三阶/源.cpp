#include<stdio.h>
#include<stdlib.h>
void Hanoi(int n, char start, char temp, char finish);
int  times(int n);
int i;
//从A柱移动到C柱,temp为临时柱（辅助柱）
//有三根棒为A、B、C。A棒上叠放着n个大小不等的盘，依次叠加为大盘在下，小盘在下。
//要求把这n个盘移到C棒上，在移动过程中可以借助B棒
//1、每次只能移一个盘
//2、在移动过程中必须保持3根棒上的大盘在下，小盘在上
//3、盘子只能在3根柱子间移动，不能放在他处

void Hanoi(int n, char start, char temp, char finish)
//递归时调换顺序,使移动步骤均为start->finish   
{
	if (n == 1){
		printf("%c->%c\t", start, finish);
	}
	else 
	{
		Hanoi(n - 1, start/*A*/, finish/*B*/, temp/*C*/);//把A上（n-1）个盘子从A借助C移动到B
		printf("%c->%c\t", start/*A*/, finish/*C*/);//把A剩下的最大的盘子由A移到C
		Hanoi(n - 1, temp/*A*/, start/*B*/, finish/*C*/);//把移到B的(n-1)个盘子从B借助A移到C
	}
}

int times(int)//次数函数（2^n-1,n为盘数)
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
	printf("总共有几个盘子：\n");
	scanf("%d", &i);
	Hanoi(i, 'A', 'B', 'C');//这里的'A','B','C'与上述Hanoi函数里后面的对应
	printf("移动次数：%d\n", times(i));
	system ("pause");
	return 0;
}