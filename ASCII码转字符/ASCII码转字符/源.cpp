#include<stdio.h>
int main()
{
	int s;
	char ch;
	printf("ASCII��Ϊ:");
	scanf("%d", &s);
	if (s <= 255 && s >= 0)
	{
		ch = s;
		printf("%d���ַ�Ϊ%c\n\n", s, ch);
	}
	else printf("error\n\n");

	return main();
}