#include <stdio.h>
#include <math.h>

int main ()
{
	long int a, b, c;

	scanf("%ld", &a);
	scanf("%ld", &b);
	
	c = powl (a, b);
	printf ("%ld \n", c);
	
    return 0;
}
