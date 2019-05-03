#include<stdio.h>
#include<math.h>

int main()
{
	while (1){
		int data, mid, sum = 1;
		int i, j;
		scanf("%d", &data);
		if (data == 0) break;
		mid = sqrt(data) + 1;
		if (data==1||data==2) sum = 1;
		if (data > 1 && data % 2 == 1)//ÆæÊý
		{
			++sum;
			for (i = 3; i < data/2; ++i)
			{
				if (data%i == 0)
				{
					int tmp = data / i;
					if (tmp % 2 == 1) ++sum;
				}
			}
		}
		if (data > 2 && data % 2 == 0)//Å¼Êý
		{
			for (j = 2; j < data/2; ++j)
			{
				if (data%j == 0)
				{
					int tmp = data / j;
					if (tmp % 2 == 1) ++sum;
				}
			}
		}
		printf("%d\n", sum);
	}
}
