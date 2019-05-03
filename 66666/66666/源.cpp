#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;
int k[100002];

int main()
{
	int n, i;
	while (scanf("%d", &n) != EOF)
	{
		if (n % 2 == 0) continue;

		for (i = 0; i < n; ++i){
			scanf("%d", &k[i]);
			char ch;
			ch = getchar();
			if ('ch' == '\n') break;
		}
		sort(k, k + n);
		if (n == 1)
		{
			printf("%d\n", k[0]);
		}
		int p = 0;
		if (n >= 2){
			while (p <= n)
			{
				if (k[p] == k[p + 1]) p += 2;
				if (k[p] != k[p + 1])
				{
					printf("%d\n", k[p]);
					break;
				}
			}
		}
	}
	return 0;
}

