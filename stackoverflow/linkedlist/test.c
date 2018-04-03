#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
	int data;
	// stuff to be added later
} Cell;

typedef struct Grid {
	unsigned width;
	unsigned height;
	Cell *cell;
} Grid;

Grid initGrid(unsigned width, unsigned height) {
	Grid g;
	g.width = width;
	g.height = height;
	g.cell = malloc( sizeof(Cell[height][width]) );
	return g;
}
int main(int argc, char ** argv)
{
	unsigned int height;
	unsigned int width;
	int i,j;
	Grid test;

	printf("enter width: ");
	scanf("%d", &width);
	printf("enter height: ");
	scanf("%d", &height);
	test = initGrid (width, height);

	for (i = 0; i < height; i++ )
		for (j = 0; j < width; j++ )
			test.cell[i][j].data = i;

	for (i = 0; i < height; i++ ) {
		for (j = 0; j < width; j++ )
			printf("%d ", test.cell[i][j].data);
		printf("\n");
	}
}
