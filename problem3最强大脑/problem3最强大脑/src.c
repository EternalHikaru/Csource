#include<stdio.h>
#include<stdlib.h>
void sort(int *S, int *AS, int *question, int n,int m);

int main()
{
	int *S, *question, n,m,*AS;
	scanf("%d %d", &n, &m);
	S = (int *)calloc(n, sizeof(int));
	AS = (int *)calloc(m, sizeof(int));
	question = (int *)calloc(m, sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &S[i]);
	}
	for (int j = 0; j < m; ++j)
	{
		scanf("%d", &question[j]);
	}
	sort(S, AS, question, n,m);
	for (int k = 0; k < m; ++k)
	{
		printf("%d\n", AS[k]);
	}
	free(S);
	free(AS);
	free(question);
	return 0;
}

void sort(int *S, int *AS, int *question,int n,int m)
{
	int low = 0, high = n - 1,mid;
	for (int i = 0; i < m; ++i){
		while (low <= high)
		{
			if (question[i] == 0)
			{
				AS[i] = 0;
				break;
			}
			mid = (low + high) / 2;
			if ((question[i] > S[mid]) && question[i]<S[mid + 1]) {
				AS[i] = mid + 1;
				low = 0;
				high = n - 1;
				break;
			}
			if ((question[i] == S[mid]) && question[i]<S[mid + 1]) {
				AS[i] = mid;
				low = 0;
				high = n - 1;
				break;
			}
			if ((question[i] > S[mid]) && question[i]==S[mid + 1]) {
				AS[i] = mid + 1;
				low = 0;
				high = n - 1;
				break;
			}
			if ((question[i] == S[mid]) && question[i]==S[mid + 1]) {
				AS[i] = mid + 1;
				low = 0;
				high = n - 1;
				break;
			}
			else if (question[i]>S[mid+1]) low = mid + 1;
			else if(question[i]<S[mid])  high = mid;
		}
	}
}