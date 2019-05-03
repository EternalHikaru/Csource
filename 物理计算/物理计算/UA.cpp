#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define max 9999
int ReadArray(double array[]);


int ReadArray(double array[])
{
	int i;
	for (i = 0; i < max; ++i)
	{
		scanf("%lf", &array[i]);
		char a = getchar();
		if (a == '\n') break;
	}
	return i;
}
int main()
{
	
	double data[max], S=0, averagy, UA, a = 0;
	int i, r,size;
	printf("依次输入数据：(回车作结)\n");
	size=ReadArray(data);
	for (i=0; i <=size ; ++i) {
		S += data[i];
	}
	averagy = S / (size+1);
	for (r=0; r <= size; ++r)
	{
		a += (data[r] - averagy)*(data[r] - averagy);
	}
	UA = sqrt(a / ((size+1) * size));

	printf("UA=%f", UA);
	printf("\n");
	system("pause");
	return 0;
}




