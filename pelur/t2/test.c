#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main () {
	int tmp,sum = 0;
	int term1 = 0, term2 = 1;

	do
	{
		tmp = term2 + term1;
		printf("%d ",tmp);
		if ( (tmp % 2) == 0 ) sum += tmp;
		term1 = term2;
		term2 = tmp;
	} while (tmp < 4000000);

	printf("\nthe sum is: %d\n", sum);
}
