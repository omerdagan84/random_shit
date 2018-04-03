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
	int a, b, c;

	for ( a=1 ; a<700 ; a++)
		for ( b=1 ; b<700 ; b++)
			for( c=1 ; c<700 ; c++)
			{
				if ( ( a > b || b > c || a > c) || (a + b + c) != 1000 ) {
					continue;
				} else {
					if ( (a*a) + (b*b) == (c*c) ) {
						printf("result is a-%d b-%d c-%d product-%d", a, b, c, (a*b*c));
						return;
					}

				}
			}
}
