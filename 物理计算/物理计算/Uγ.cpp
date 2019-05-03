#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define P(a) a*a

int main()
{
	printf("请依次输入:Urm UrV UrT UrP Urd(输入百分号前数据即可）\n");
	double data[5], Uy;
	int i;
	for (i = 0; i <= 4; ++i)
	{
		scanf("%lf", &data[i]);
	}
	Uy = sqrt(P(data[0]) + P(data[1]) + 2 * P(data[2]) + P(data[3]) + 4 * P(data[4]));
	printf("%f", Uy);
	system("pause");
	return 0;
}