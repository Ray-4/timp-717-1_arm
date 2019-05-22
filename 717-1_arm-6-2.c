#include <stdio.h>
#include <stdlib.h>

// сортировка Шелла
int sorting_function (int *arr, int len)
{
	int k = 0, comp = 0;
	int i, j, step, tmp;
	step = len / 2;

	for (step; 0 < step; step /= 2)
	{
		for (i = step; i < len; i++)
		{
			tmp = arr[i];
			
			for (j = i; step <= j; j -= step)
			{
				comp += 1;
				if (tmp < arr[j - step])
				{
					arr[j] = arr[j - step];
					k += 1;			
				}
				else 
				{
					break;
				}
			}
			arr[j] = tmp;
		}
		
	}

	return k, comp;
}

int main ()
{
	int n, i, a;
	int *arr = NULL;

	scanf ("%d", &n);
	
	
	// (n * sizeof(int) - сколько байт необходимо выделить
	// sizeof(int) - размер одного элемента массива
	arr = (int*) malloc (n * sizeof(int));

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);
		arr[i] = a;
	}
	
	sorting_function (arr, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
		if (i != n-1)
		{
			printf (" ");
		}
	}
	
	printf("\n");

	return 0;
}
