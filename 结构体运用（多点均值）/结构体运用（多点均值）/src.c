#include<stdio.h>


struct point {
	double x;
	double y;
};
typedef struct point Point;
Point *po;

void getpoint(int);
Point center(Point *po,int size);

int main()
{
	int n;
	printf("��ĸ���:");
	scanf("%d", &n);
	Point result;
	
	getpoint(n);
	result = center(po, n);
	printf("���ĵ�λ�ã�(%lf,%lf)", result.x, result.y);
	printf("\n");
	return 0;
}

void getpoint(int n)
{

	double x, y;
	po = (double *)calloc(n, sizeof(Point));//����
	for (int i = 0; i < n;++i)
	{
		scanf("%lf", &x);
		scanf("%lf", &y);//�ṹ��ָ����÷�ʽ��->
		(po + i)->x = x;
		(po + i)->y = y;
	}
	free(*po);
}

Point center(Point *po,int size)
{
	Point result;
	int i;
	result.x = 0;
	result.y = 0;
	for (i = 0; i < size; ++i)
	{
		result.x += (po+i)->x;
		result.y += (po+i)->y;
	}
	result.x /= size;
	result.y /= size;
	return result;

}