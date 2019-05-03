#include<stdio.h>

int main()
{
	int n, F, T, ten, five, one;
	while ((scanf("%d", &n) != EOF))
	{
		F = n / 50;
		T = (n - 50*F) / 20;
		ten = (n - 50*F - 20 * T) / 10;
		five = (n - 50*F - 20 * T - 10 * ten) / 5;
		one = n - 50*F - 20 * T - 10 * ten-5*five;
		if (F!=0&&T!=0&&ten!=0&&five!=0&&one!=0)
		printf("50*%d+20*%d+10*%d+5*%d+1*%d\n", F, T, ten, five, one);
		if (F == 0 && T != 0 && ten != 0 && five != 0 && one != 0)
			printf("20*%d+10*%d+5*%d+1*%d\n",  T, ten, five, one);
		if (F!=0&& T == 0 && ten != 0 && five != 0 && one != 0)
			printf("50*%d+10*%d+5*%d+1*%d\n",  F, ten, five, one);
		if (F != 0 && T != 0 && ten == 0 && five != 0 && one != 0)
			printf("50*%d+20*%d+5*%d+1*%d\n", F, T, five, one);
		if (F != 0 && T != 0 && ten != 0 && five == 0 && one != 0)
			printf("50*%d+20*%d+10*%d+1*%d\n", F, T, ten,  one);
		if (F != 0 && T != 0 && ten != 0 && five != 0 && one == 0)
			printf("50*%d+20*%d+10*%d+5*%d\n",  F, T, ten, five);
		if (F == 0 && T == 0 && ten != 0 && five != 0 && one != 0)
			printf("10*%d+5*%d+1*%d\n",  ten, five, one);
		if (F == 0 && T != 0 && ten == 0 && five != 0 && one != 0)
			printf("20*%d+5*%d+1*%d\n",  T, five, one);
		if (F == 0 && T != 0 && ten != 0 && five == 0 && one != 0)
			printf("20*%d+10*%d+1*%d\n",  T, ten, one);
		if (F == 0 && T != 0 && ten != 0 && five != 0 && one == 0)
			printf("20*%d+10*%d+5*%d\n",  T, ten, five);
		if (F != 0 && T == 0&& ten == 0 && five != 0 && one != 0)
			printf("50*%d+5*%d+1*%d\n",  F,  five, one);
		if (F != 0 && T == 0 && ten != 0 && five == 0 && one != 0)
			printf("50*%d+10*%d+1*%d\n",  F,  ten,  one);
		if (F != 0 && T == 0 && ten != 0 && five != 0 && one == 0)
			printf("50*%d+10*%d+5*%d\n", F,ten, five);
		if (F != 0 && T != 0 && ten == 0 && five == 0 && one != 0)
			printf("50*%d+20*%d+1*%d\n",F, T,  one);
		if (F != 0 && T != 0 && ten == 0 && five != 0 && one == 0)
			printf("50*%d+20*%d+5*%d\n", F, T, five );
		if (F != 0 && T != 0 && ten != 0 && five == 0 && one == 0)
			printf("50*%d+20*%d+10*%d\n",  F, T, ten);
		if (F == 0 && T == 0 && ten == 0 && five != 0 && one != 0)
			printf("5*%d+1*%d\n",  five, one);
		if (F == 0 && T == 0 && ten != 0 && five == 0 && one != 0)
			printf("10*%d+1*%d\n",  ten,one);
		if (F == 0 && T == 0 && ten != 0 && five != 0 && one == 0)
			printf("10*%d+5*%d\n",  ten, five );
		if (F == 0 && T != 0 && ten == 0 && five == 0 && one != 0)
			printf("20*%d+1*%d\n",T, one);
		if (F == 0 && T != 0 && ten == 0 && five != 0 && one == 0)
			printf("20*%d+5*%d\n", T, five);
		if (F != 0 && T != 0 && ten == 0 && five == 0 && one == 0)
			printf("50*%d+20*%d\n",  F, T);
		if (F != 0 && T == 0 && ten != 0 && five== 0 && one == 0)
			printf("50*%d+10*%d\n",  F,  ten );
		if (F != 0 && T == 0 && ten == 0 && five == 0 && one != 0)
			printf("50*%d+1*%d\n",  F,one);
		if (F != 0 && T == 0 && ten == 0 && five != 0 && one == 0)
			printf("50*%d+5*%d\n", F,  five);
		if (F == 0 && T != 0 && ten != 0 && five == 0 && one == 0)
			printf("20*%d+10*%d\n", T, ten);
		if (F != 0 && T == 0 && ten == 0 && five == 0 && one == 0)
			printf("50*%d\n",  F);
		if (F == 0 && T != 0 && ten == 0 && five == 0 && one == 0)
			printf("20*%d\n", T);
		if (F == 0 && T == 0 && ten != 0 && five == 0 && one == 0)
			printf("10*%d\n", ten);
		if (F == 0 && T == 0 && ten == 0 && five != 0 && one == 0)
			printf("5*%d\n", five);
		if (F == 0 && T == 0 && ten == 0 && five == 0 && one != 0)
			printf("1*%d\n",  one);
	
	}
}