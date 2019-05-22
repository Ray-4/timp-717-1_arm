#include <stdio.h>
#include <stdlib.h>

// быстрая сортировка
// для подсчета сравнений и перестановок 
int k = 0, comp = 0;

int sorting_function (int *arr, int left, int right)
{
	
	int i, temp;
	
	int l = left, r = right;
	int piv = arr[(l + r) / 2]; // Опорным элементом для примера возьмём средний
	
	while (l <= r)
	{
		k++;
		while (arr[l] < piv)
		{
			l++;
			k++;
		}

		k++;
		while (arr[r] > piv)
		{
			r--;
			k++;
		}

		k++;
		if (l <= r)
		{
			temp = arr [l];
			arr[l] = arr[r];
			arr[r] = temp;
			l++;
			r--;
			comp++;
		}		
	}
	k++;
	if (left < r)
		sorting_function (arr, left, r);
	
	k++;
	if (right > l)
		sorting_function (arr, l, right); 

	return 0;
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
	
	sorting_function (arr, 0, n - 1);

	for (i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
		if (i != n-1)
		{
			printf (" ");
		}
	}
	printf("\n");
	// количество сравнений и перестановок
	//printf ("%d %d \n", k, comp);

	return 0;
}
