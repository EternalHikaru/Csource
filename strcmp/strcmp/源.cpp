#include<stdio.h>
#include<stdlib.h>
#define max 999
int strcmp(char *s1, char *s2);

int strcmp(char *s1, char *s2)
{
	int S1, S2;
	char *c1=s1, *c2=s2;
	for (S1 = 0; S1<max; ++S1)
	{
		if (*s1 == '\0') break;
		++s1;
	}
	for (S2 = 0; S2<max; ++S2)
	{
		if (*s2 == '\0') break;
		++s2;
	}
	if (S1>S2) return 1;
	if (S1<S2) return -1;
	if (S1 == S2){
		while (*c1&&*c2)
		{
			if (*c1 > *c2) return 1;
			if (*c1 < *c2) return -1;
			++c1;
			++c2;
		}
		if (*c1 == '\0'&& *c2 == '\0') return 0;
		if (*c1 == '\0') return -1;
		else return 1;
	}
}

int main()
{
	int result;
	char s1[max], s2[max];
	scanf("%s %s", &s1, &s2);
	result=strcmp(s1, s2);
	printf("%s%s%s\n", s1, ((result == 1) ? "大于" : (result == 0) ? "等于" : "小于"), s2);
	system("pause");
	return 0;
}