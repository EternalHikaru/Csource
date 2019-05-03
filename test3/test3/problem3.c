#include<stdio.h>
#include<string.h>
int Adjust(char s[], char as[]);
char S[2000005];
char AS[2000005];

int Adjust(char s[], char as[])
{
	int a=0, i = 1;
	as[0] = '#';
	while (s[a] != '\0')
	{
		as[i++] = s[a];
		as[i++] = '#';
		++a;
	}
	return i;
}
int main()
{
	int i,j,length,maxlen=0;
	scanf("%s", &S);
	length = Adjust(S, AS);
	if (AS == NULL||length<1) return 0;
	for (j = 0; j < length; ++j)
		{
			for (i = 0; j-i>=0&&j+i<length; ++i){
				if (AS[j - i] != AS[j + i]) break;
			}
			if (i>maxlen) maxlen = i;
		}
	printf("%d\n", maxlen-1);
	return 0;
}
	