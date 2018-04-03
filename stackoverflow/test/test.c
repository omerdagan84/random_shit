#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main () {
	char mapp[100][100];
	int i, count = 0;
	char filename[32];

	sprintf(filename, "test.txt");
	FILE *open = fopen(filename, "r");
	if(!open){
		printf("error");
	}

	while(!feof(open)){
		fscanf(open, "%[^\n]\n", mapp[count]); 
		count++;
	}
	fclose(open);

	for(i = 0; i < count ; i++){
		printf("%s\n", mapp[i]);
	}
}
