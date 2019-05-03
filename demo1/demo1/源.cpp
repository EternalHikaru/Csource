#include<stdio.h>
#include<string.h>
char a[2000010];
char b[2000010];
char c[2000010];

int main()
{
	int m, n, p, q;
	scanf("%s", a);
	m = strlen(a);
	for (n = 0; n<m * 2; n += 2)
	{
		b[n] = '#', b[n + 1] = a[(n + 1) / 2];
	}
	b[2 * m] = '#', b[2 * m + 1] = '\0';
	int x, y, z;
	c[0] = 1;
	for (q = 1; q<m * 2; q++)
	{
		x = 1, y = 1;
		while (b[q - x] == b[q + x])
		{
			x = x + 1, y = y + 1;
			if (q - x<0 || q + x>m * 2)
				break;
		}
		c[q] = y;
		c[2 * m] = '\0';
	}

	p = c[0];
	for (z = 1; z<2 * m; z++)
	if (p<c[z])
		p = c[z];
	else
	{
		p = p;
	}
	printf("%d", p - 1);
	printf("\n");
}
