#include<stdio.h>
int main()
{
	int s;
	char ch;
	printf("ASCIIÂëÎª:");
	scanf("%d", &s);
	if (s <= 255 && s >= 0)
	{
		ch = s;
		printf("%dµÄ×Ö·ûÎª%c\n\n", s, ch);
	}
	else printf("error\n\n");

	return main();
}