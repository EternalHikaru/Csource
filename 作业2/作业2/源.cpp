#include <stdio.h>

int main()
{
	double w,h,bmi;
	int a;
	printf("���������(m)������(kg):\n");
	scanf("%lf %lf", &h,&w);
	bmi = w / (h*h);
	if (bmi < 18.5)
		a = 0;
	else if (bmi < 23.9)
		a = 1;
	else if (bmi < 27.9)
		a = 2;
	else a = 3;
		switch (a)
	{
	case 0:printf("��ķ���ָ����ƫ��\n");
		break;
	case 1:printf("��ķ���ָ��������\n");
		break;
	case 2:printf("��ķ���ָ���ǳ���\n");
		break;
	case 3:printf("��ķ���ָ���Ƿ���\n");
		break;



	}
	return main();

	


}