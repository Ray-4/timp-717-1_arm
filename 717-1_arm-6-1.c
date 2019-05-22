#include <stdio.h>
#include <stdlib.h>

int sorting_function (int *arr, int arr_len)
{
	int k = 0, tmp, j;
	int s = arr_len;

	while (arr_len > 1)
	{	
		s /= 1.247;
		j = 0; // кол-во перестановк
		if (s < 1)
		{
			s = 1;
		}

		for (int i = 0; i + s < arr_len; i++)
		{
			if (arr[i] > arr[i + s])
			{
				tmp = arr[i];
				arr[i] = arr[i + s];
				arr[i + s] = tmp;
				k += 1; // количесвто сравнений и перестановок в сумме
				j = i; // количесвто перестановок 
			}
		}
		// условие останова
		if (s == 1)
		{
			arr_len = j + 1;
		}
	}
	return k;
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
			printf(" ");
		}
	}
		
	printf("\n");
	return 0;
}
