#include<stdio.h>
#include<stdlib.h>

int main()
{
	int row, clo, i, j,**a;
	printf("Ҫ������ά���������������Ϊ��\n");
	scanf("%d %d", &row, &clo);
	a = (int **)calloc(row, sizeof(int *));//ָ��ָ���ָ�루ÿһ���׵�ַ��ע������ָ���С��ʾ��ʽΪsizeof(int *)
	for (i = 0; i < row; ++i)
	{
		a[i] = (int *)calloc(clo, sizeof(int));//Ϊÿһ�з���ռ�
	}
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < clo; ++j)
		{
			printf("a[%d][%d]=", i+1, j+1);//����+1��Ϊ��ϰ������ʽ��1��1�п�ʼ
			scanf("%d", &a[i][j]);
		}
	}
	printf("\n");
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < clo; ++j)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < row; ++i)
		free(a[i]);//�ͷ�ÿһ�пռ�
	free(a);//�ͷ�ÿһ���׵�ַ�ռ䣬���ܿռ�
	system("pause");
	return 0;
}