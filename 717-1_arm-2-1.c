#include <stdio.h>

int main ()
{
	long int n;
	long int a;
	long int b = -2147483647;
	int c = 1;
	int i;
    scanf("%ld", &n);

	for (i = 0; i < n; i++)
	{
		a = b;
		scanf ("%ld", &b);	
		if ((a <= b) && (c == 1))
		{
			c = 1;
		}
		else 
		{
			c = 0;
		}
	}

	printf ("%d \n", c);

	return 0;
}
