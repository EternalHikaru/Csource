/* �ļ�����1-1.c
   �ñ�׼��ʽ���һԪ���η���*/

#include <stdio.h>
#include<math.h>

int main()
{   
	double a,b,c,x1,x2,dlt;

	printf("�����뷽�̵�3��ϵ��: ");

	scanf("%lf %lf %lf",&a, &b, &c);

	dlt = b * b - 4 * a * c;
	x1 = (-b + sqrt(dlt))/ 2 / a; x2 = (-b - sqrt(dlt))/ 2 / a;
	if (dlt<0) printf("The equation has no real solution\n\n");
	if (dlt==0) printf("The equation has only one solution:%.10f\n\n",x1);
    if (dlt>0) printf("x1=%.10f  x2=%.10f\n\n",x1,x2);

		
	return main();
}