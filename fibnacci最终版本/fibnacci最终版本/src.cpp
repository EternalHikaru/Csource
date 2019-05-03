#include<iostream>
using namespace std;
const int maxbit = 2000;
int tmp[3][maxbit] = { 0 };

int main()
{
	int n;
	char result[maxbit] = { '\0' };
	memset(tmp, 0, sizeof(tmp));
	cin >> n;
	if (n <= 0) return 0;
	else
	{
		tmp[0][0] = 1;
		tmp[1][0] = 1;
		tmp[2][0] = 2;
		int i, t;
		int num = 0;
		for (i = 0; i < n - 1; ++i)
		{
			for (int p = 0; p < maxbit; ++p)
			{
				tmp[i % 3][p] = tmp[(i + 1) % 3][p] + tmp[(i + 2) % 3][p];
			}
			for (int m = 0; m < maxbit; ++m)
			{
				if (tmp[i % 3][m] >= 10)
				{
					tmp[i % 3][m + 1] += (tmp[i % 3][m] / 10);
					tmp[i % 3][m] %= 10;
				}
			}
		}
		for (t = maxbit - 1; t >= 0; --t)
		{
			if (tmp[(n - 1) % 3][t] != 0)
			{
				num = t;
				break;
			}
		}
		for (int s = 0; s <= num; ++s)
		{
			result[s] = tmp[(n - 1) % 3][s] + '0';
		}
		cout << "fib(" << n << ")=";
		for (int s = num; s >= 0; --s)
		{
			cout << result[s];
		}

		cout << '\n';
	}
	system("pause");
	return main();
}