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
void main () {
	int test = 20;
	int found = 0;
	int i;
	while ( !found ) {
		for (i = 1; i <= 20; i++) {
			if ( (test % i) != 0 ) break;
		}
		if (i == 21) {
			found =1;
		} else {
			test++;
		}
	}
	printf("test - %d", test);
}
