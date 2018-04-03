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
	char filename[32];
	char mapp[1001];
	long count = 0;
	long i;
	long tmp, max = 0;


	sprintf(filename, "test.txt");
	FILE *open = fopen(filename, "r");
	if(!open){
		printf("error");
	}

	fscanf(open, "%1000s", mapp); 
	fclose(open);

	for(i = 0; i < 1000 - 1 - 13 ; i++){
		tmp = 1;
		for (int j = 0 ; j < 13 ; j++)
		{
			tmp *= ((long)mapp[i + j]-48);
		}
		if (tmp > max) max = tmp;
	}
	printf("max is %ld", max);
}
