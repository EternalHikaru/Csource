#include <stdio.h>
#include<math.h>

int main()
{
	double a, b, c, dlt, x1, x2;
	printf("��������ⷽ�̵�����ϵ����a b c\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	if (a==0)
	    if (b == 0) printf("�Ƿ�����\n");
		else printf("Ψһ�⣺%.3f", -c / b);
	else
	{
		dlt = b*b - 4 * a*c;
		if (dlt < 0) printf("�÷�����ʵ����\n");
		else if (dlt == 0)  printf("Ψһ�⣺%.3f\n", -b / 2 / a);
		else {
			x1 = (-b + sqrt(dlt)) / 2 / a;
			x2 = (-b - sqrt(dlt)) / 2 / a;
			printf("���⣺x1=%.3f x2=%.3f\n", x1, x2);
		}
	}
	return 0;
}
