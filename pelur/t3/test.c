#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPrime(long to_test)
{
	int i;

	for (i=1 ; i <= to_test ; i++)
	{
		if ( ((to_test % i) == 0) && ((i != 1) && (i != to_test)))
			return 0;
	}
	printf("prime found: %ld\n", to_test);
	return 1;
}

void main () {
	long i=1, tmp, sum = 0;
	long limit = 600851475143;

	while ( 1 ) {
		if (isPrime(i)) {
			if ( limit % i == 0 ) {
				limit = limit / i;
				printf("limit after devision %ld and iterator %ld\n", limit, i);
			}
		}
		if ( limit == 1 ) break;
		i++;
	}

	printf("\nthe last is : %ld\n", i);
}
