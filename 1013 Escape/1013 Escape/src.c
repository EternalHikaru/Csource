#include<stdio.h>
#include<math.h>

int main()
{
	int x, p, n;
	char s[32] = { '\0' };
	char result[32] = { '\0' };
	while (1)
	{
		int sum = 0;
		scanf("%d %d %d", &x, &p, &n);
		if (x == 0 && p == 0 && n == 0) break;
		int r = 0;
		while (1)
		{
			if (x % 2 == 0)
			{
				x = x / 2;
				s[r++] = '0';
			}
			if (x % 2 == 1)
			{
				x = (x - 1) / 2;
				s[r++] = '1';
			}
			if (x == 0) break;
		}
		int j = 0;
		for (int i = p - n + 1; i <= p; ++i)
		{
			result[j++] = s[i];
		}
		for (int i = 0; i < j; ++i)
		{
			sum += (result[i] - '0')*(int)(pow(2, i));
		}
		printf("%d\n", sum);
	}
}