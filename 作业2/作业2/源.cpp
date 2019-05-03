#include <stdio.h>

int main()
{
	double w,h,bmi;
	int a;
	printf("请输入身高(m)与体重(kg):\n");
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
	case 0:printf("你的肥胖指数是偏瘦\n");
		break;
	case 1:printf("你的肥胖指数是正常\n");
		break;
	case 2:printf("你的肥胖指数是超重\n");
		break;
	case 3:printf("你的肥胖指数是肥胖\n");
		break;



	}
	return main();

	


}