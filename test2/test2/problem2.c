#include<stdio.h>

int main()
{
	int Y, M, D, S;
	scanf("%d %d %d", &Y, &M, &D);
	if (Y % 4 == 0 && Y % 100 != 0||Y % 400 == 0 )
	{
		switch (M)
		{
		case 1:S = D; break;
		case 2:S = 31 + D; break;
		case 3:S = 31 + 29 + D; break;
		case 4:S = 31 + 29 + 31 + D; break;
		case 5:S = 31 + 29 + 31 + 30 + D; break;
		case 6:S = 31 + 29 + 31 + 30 + 31 + D; break;
		case 7:S = 31 + 29 + 31 + 30 + 31 + 30 + D; break;
		case 8:S = 31 + 29 + 31 + 30 + 31 + 30 + 31 + D; break;
		case 9:S = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + D; break;
		case 10:S = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + D; break;
		case 11:S = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + D; break;
		case 12:S = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + D; break;
		}
	}
	else
	{
		switch (M)
		{
		case 1:S = D; break;
		case 2:S = 31 + D; break;
		case 3:S = 31 + 28 + D; break;
		case 4:S = 31 + 28 + 31 + D; break;
		case 5:S = 31 + 28 + 31 + 30 + D; break;
		case 6:S = 31 + 28 + 31 + 30 + 31 + D; break;
		case 7:S = 31 + 28 + 31 + 30 + 31 + 30 + D; break;
		case 8:S = 31 + 28 + 31 + 30 + 31 + 30 + 31 + D; break;
		case 9:S = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + D; break;
		case 10:S = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + D; break;
		case 11:S = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + D; break;
		case 12:S = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + D; break;
		}
	}
	printf("%d", S);
	return 0;
}