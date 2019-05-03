#include<stdio.h>
#include<math.h>
#include<string.h>
#define max(x,y) x<y?y:x

int main()
{
	int len_a, len_b, t, j1 = 0, j2 = 0;
	char a[102];
	char b[102];
	int A[102] = { 0 }, B[102] = { 0 }, S[102] = { 0 };
	scanf("%s%s", a, b);

	len_a = strlen(a);
	len_b = strlen(b);

	for (int i = len_a - 1; i >= 0; --i)//len-1 跳过\0（***）
	{
		A[j1++] = a[i] - '0';
	}
	for (int i = len_b - 1; i >= 0; --i)
	{
		B[j2++] = b[i] - '0';
	}
	t = max(len_a, len_b);
	for (int i = 0; i < t; ++i)
	{
		S[i] = A[i] + B[i];
	}
	for (int i = 0; i < t; ++i){
		if (S[i] >= 10)
		{
			S[i + 1] += S[i] / 10;//开数组时稍大即可放下S[t}
			S[i] = S[i] % 10;
		}
	}
	if (S[t] == 0)
	{
		for (int i = t - 1; i >= 0; --i)
		{
			printf("%d", S[i]);
		}
		printf("\n");
	}
	else{
		for (int i = t; i >= 0; --i)
		{
			printf("%d", S[i]);
		}
		printf("\n");
	}
}
