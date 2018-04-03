#include<stdio.h>
#include<stdint.h>

#define WIDTH 10
int main()
{
	int iter = 0;
	int x = 0,y = 0;
	while ( iter < (WIDTH*4) ) {
		if ( iter < WIDTH ) {
			x = iter;
			y = 0;
		} else if ( iter >= WIDTH && iter < ( 2 * WIDTH ) ) {
			x = WIDTH -1;
			y = (iter % WIDTH) ;
		} else if ( iter >= (2 * WIDTH) && iter < ( 3 * WIDTH ) ) {
			x = (WIDTH) - (iter - (2 * WIDTH)) - 1;
			y = WIDTH - 1;
		} else {
			x = 0;
			y = (4 * WIDTH) - iter - 1;
		}
		printf("(%d, %d) ", x+1 ,y+1 );
		iter++;
	}
	printf("\n");

	return 0;
}
