#include<stdio.h>
int Longest(char *,char *);
void Max(int length, char *CS, int *p);
#define min(a,b) a<b?a:b
char AS[2000005];
char A[2000005];
int p[2000005];

int Longest(char *A,char *AS)
{
	int i = 0, a = 1;
	AS[0] = '$';
	while (A[i] != '\0')
	{
		AS[a++] = '#';
		AS[a++] = A[i];
		i++;
	}
	AS[a++] = '#';
	AS[a] = '\0';
	
	return a;
}

void Max(int length, char *CS, int *p)
{
	int id = 0, mx = 0;
	for (int i = 0; i < length; ++i)
	{
		p[i] = mx > i ? (min(p[2 * id - i], mx - i)) : 1;
		while (AS[i - p[i]] == AS[i + p[i]])
		{
			++p[i];
		}
		if (p[i] + i > mx) {
			mx = i + p[i];
			id = i;
		}
	}
}
int main()
{
	int maxlen=0,length;
	scanf("%s", A);
	length = Longest(A,AS);
	Max(length, AS, p);
	for (int i = 0; i<length;++i){
		if (p[i]>maxlen) maxlen = p[i];
	}
	printf("%d\n", maxlen-1);
	return 0;

}
