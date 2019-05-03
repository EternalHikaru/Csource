#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	char *ch;
	scanf("%d", &n);
	getchar();
	ch = (char *)calloc(n+1,sizeof(char));
	gets(ch);
	int bool1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (ch[i] == ' ')
		{
			bool1 = 1;
			break;
		}
	}
	if (bool1) printf("YES");
	
	if(!bool1) printf("NO");
	free(ch);
}