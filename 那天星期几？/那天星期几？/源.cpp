#include <stdio.h>
//低级版

int main()
{
	int  Y, R, a, b, s, m, T;
	printf("截止时间：2017年  月  日\n");
	scanf("%d  %d", &Y, &R);
	a = Y - 1;
	b = R - 1;

	switch (a)
	{
	case 0:  s = b;
		break;
	case 1:s = 31 + b;
		break;
	case 2:s = 31 + 28 + b;
		break;
	case 3:s = 31 + 28 + 31 + b;
		break;
	case 4:s = 31 + 28 + 31 + 30 + b;
		break;
	case 5:s = 31 + 28 + 31 + 30 + 31 + b;
		break;
	case 6:s = 31 + 28 + 31 + 30 + 31 + 30 + b;
		break;
	case 7:s = 31 + 28 + 31 + 30 + 31 + 30 + 31 + b;
		break;
	case 8:s = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + b;
		break;
	case 9:s = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + b;
		break;
	case 10:s = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + b;
		break;
	case 11:s = 31 + 28 + 31 + 30 + 30 + 31 + 31 + 31 + 30 + 31 + 30 + b;
		break;
	}

	m = s % 7;
	switch (m)
	{
	case 0: T =7;
		break;
	case 1: T = 1;
		break;
	case 2: T = 2;
		break;
	case 3:T = 3;
		break;
	case 4:T = 4;
		break;
	case 5:T = 5;
		break;
	case 6:T = 6;
		break;
	}

	printf("2017年%d月%d日是星期%d\n", Y, R, T);
	return main();
}
		