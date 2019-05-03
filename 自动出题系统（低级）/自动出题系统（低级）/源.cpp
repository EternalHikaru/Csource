#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<time.h>

// 本程序为五位数加减与二位数乘与四位数除出题器（有待完善)

int main()
{
	int num1, num2,num3,num4,num5,num6, op, result1, result2;

	srand(time(NULL));
	srand(time(0));


	num1 = rand() ;
	num2 = rand() ;
	num3 = rand() * 100 / (RAND_MAX + 1);
	num4 = rand() * 100 / (RAND_MAX + 1);
	num5 = rand() * 10000 / (RAND_MAX + 1);
	num6 = rand() * 10000 / (RAND_MAX + 1);
	op = rand() * 4 / (RAND_MAX + 1);

	switch (op) {
	case 0: printf("%d+%d=", num1, num2);

		scanf("%d", &result1);
		printf("%s", (num1 + num2 == result1) ? "you are right!\n\n" : "you are wrong!\n\n");
		break;


	case 1:printf("%d-%d=", num1, num2);

		scanf("%d", &result1);
		printf("%s", (num1 - num2 == result1) ? "you are right!\n\n" : "you are wrong!\n\n");
		break;

	case 2:printf("%d*%d=", num3, num4);
		scanf("%d", &result1);
		printf("%s", (num3*num4 == result1 ? "you are right!\n\n" : "you are wrong!\n\n"));
		break;

	case 3:printf("%d/%d=", num5, num6);
		   scanf("%d", &result1);
		   printf("余数为:");
		   scanf("%d", &result2);
		   printf("%s", (num5 / num6== result1 && num5%num6 == result2 ? "you are right!\n\n" : "you are wrong!\n\n"));
		   break;
	}

	system("pause");

	return main();
}
