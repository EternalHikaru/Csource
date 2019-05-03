/* 文件名：1-1.c
   用标准公式解决一元二次方程*/

#include <stdio.h>
#include<math.h>

int main()
{   
	double a,b,c,x1,x2,dlt;

	printf("请输入方程的3个系数: ");

	scanf("%lf %lf %lf",&a, &b, &c);

	dlt = b * b - 4 * a * c;
	x1 = (-b + sqrt(dlt))/ 2 / a; x2 = (-b - sqrt(dlt))/ 2 / a;
	if (dlt<0) printf("The equation has no real solution\n\n");
	if (dlt==0) printf("The equation has only one solution:%.10f\n\n",x1);
    if (dlt>0) printf("x1=%.10f  x2=%.10f\n\n",x1,x2);

		
	return main();
}