#include<stdio.h>
#include<stdlib.h>

int divide(int *, int, int);
void quicksort(int *, int, int);

int divide(int *a, int low, int high)
{
	int tmp = a[low];
	do
	{
		while (low<high&&a[high]>tmp) high--;
		if (low < high)
		{
			a[low] = a[high];
			low++;
		}
		while (low < high&&a[low] < tmp) low++;
		if (low < high)
		{
			a[high] = a[low];
			high--;
		}
	} while (low != high);
	a[low] = tmp;
	return low;
}

void quicksort(int *a, int low, int high)
{
	int mid;
	if (low >= high) return;
	mid = divide(a, low, high);
	quicksort(a, low, mid - 1);
	quicksort(a, mid + 1, high);
}

int main()
{
	int n, *array;
	scanf("%d", &n);
	array = (int *)calloc(n, sizeof(int));
	for (int p = 0; p < n; ++p)
	{
		scanf("%d", &array[p]);
	}
	quicksort(array, 0, n - 1);
	for (int q = 0; q < n; ++q)
	{
		printf("%d ", array[q]);
	}
	printf("\n");
	return 0;
}