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
	//	printf("prime found: %ld\n", to_test);
	return 1;
}

int isPlindrom (int to_test)
{
	char digit[6] = {0};
	char numOfDigit = 0;

	while ( to_test )
	{
		digit[numOfDigit++] = to_test % 10;
		to_test = to_test / 10;
	}
	for ( int i = 0 ; i < numOfDigit/2 ; i++ )
		if ( digit[i] != digit[numOfDigit - i - 1])
			return 0;
	return 1;
}

long sumOfSquars(int val)
{
	int i;
	long sum = 0;

	for (i = 1; i <= val ; i++ )
	{
		sum += i*i;
	}
	return sum;

}

long squareOfsum(int val)
{
	int i;
	long sum = 0;

	for (i = 1; i <= val ; i++ )
	{
		sum += i;
	}
	return sum*sum;
}

void main () {
	long sum = 0, iter;

	for ( iter=2 ; iter < 2000000 ; iter++) {
		if ( iter % 100000 == 0 )
			printf("iter is at %ld\n", iter);
		if (isPrime(iter))
			sum += iter;
	}
	printf("sum is = %ld\n", sum);
}
