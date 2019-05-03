#include<stdio.h>
#include<math.h>
#define pi 3.1415926

int main()
{
	
	while (1)
	{
		double a, b, v, A, S;
		scanf("%lf %lf %lf %lf %lf", &a, &b, &v, &A, &S);
		if (a<0.0000000001 && a>-0.0000000001 && b<0.0000000001 && b>-0.0000000001 && v <0.0000000001 && v>-0.0000000001 && A <0.0000000001 && A >-0.0000000001 && S <0.0000000001 && S>-0.0000000001)
			break;
		double SIN=sin(A*pi/180.0);
		double COS = cos(A*pi/180.0);
		double vx = v*COS;
		double vy = v*SIN;
		double SUMS;
		double sumhen, sumzon;
		sumhen = vy*S*0.5;
		sumzon = vx*S*0.5;
		SUMS = v*S*0.5;
		int hen = 0, zon = 0;

		hen = (sumhen - b / 2) / b + 1;
		zon= (sumzon - a / 2) / a + 1;
		printf("%d %d\n", zon, hen);
		
	}
}
