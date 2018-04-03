#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main () {
	int i,sum = 0;
	for ( i=0 ; i < 1000 ; i++ ) {
		if ( !(i % 3) || !(i % 5) ) sum += i;
	}
	printf("the sum is: %d\n", sum);
}
