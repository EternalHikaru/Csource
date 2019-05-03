#include<stdio.h>
#include<string.h>
#define min(a,b) a<b?a:b
int Adjust(char s[], char as[]);
void Maxlen(char *as, int length, int *p);
int P[2000005];
char S[2000005];
char AS[2000005];


int Adjust(char s[], char as[])
{
	int a=1,i=0;
	as[0] = '$';
	while (s[i] != '\0')
	{
		as[a++] = '@';//ÏÈ¸³Öµºó+1
		as[a++] = s[i];
		i++;
	}
	as[a++] = '@';
	as[a] =0;
	return a;
}

void Maxlen(char *as,int length,int *p)
{
	int mx=0, id=0,i,maxlen=0;
	for (i = 0; i < length; ++i)
	{
		p[i] = mx>i ? min(p[2 * id - i], mx - i) : 1;
		while (as[i + p[i]] == as[i - p[i]])
		{
			p[i]++;
		}
		if (i + p[i] > mx)
		{
			mx = i + p[i];
			id = i;
		}	
	}
}

int main()
{
	
	int length,Maxlength=0;
	scanf("%s", &S);
	length = Adjust(S, AS);
	Maxlen(AS, length, P);
	for (int i = 0; i < length; ++i)
	{
		if (P[i]>Maxlength) Maxlength = P[i];
	}
	printf("%d\n", Maxlength-1);
	return 0;
}