#include<stdio.h>
#include<string.h>

int main()
{
	int L,mid,r=1;
	char s[1001],tmp;
	scanf("%s", &s);
	L = strlen(s);
	mid = L / 2;
	for (int i = 0; i < mid/2; ++i)
	{
		tmp = s[i];
		s[i] = s[mid - i - 1];
		s[mid - i - 1] = tmp;
	}
	for (int j = mid; j < mid+mid/2; ++j)
	{
	
		tmp = s[j];
		s[j] = s[L -r];
		s[L -r] = tmp;
		r++;
	}
	printf("%s", s);

}