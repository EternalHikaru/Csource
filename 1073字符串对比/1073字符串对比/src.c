#include<stdio.h>
#include<string.h>

int main()
{
	char a[11] = { '\0' };
	char b[11] = { '\0' };
	int A, B;
	int bool1=0;
	scanf("%s", &a);
	getchar();
	scanf("%s", &b);
	getchar();
	A = strlen(a);
	B = strlen(b);
	if (A != B) printf("1");
	if (A==B)
	{
		if (strcmp(a, b) == 0) printf("2");
		else 
		{
			for (int i = 0; i < A; ++i)
			{
				if ((a[i] - 'a') != (b[i] - 'a') && (a[i] - 'A') != (b[i] - 'a') && (a[i] - 'a') != (b[i] - 'A') && (a[i] - 'A') != (b[i] - 'A'))
				{
					bool1 = 1;
				}
			}
			if (bool1) printf("4");
				else
			   {
				printf("3");
			   }
			}	
		}
	}

