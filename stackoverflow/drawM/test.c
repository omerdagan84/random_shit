#include <stdio.h>

void drawM (int size) {

	int spacesout, innerspaces; 

	int i,j; 

	spacesout = size / 2; 


	for(i=0;i<spacesout;i++) { printf(" "); } 

	printf("/\n"); 


	innerspaces = -1; 

	for(i=1; i<= size/2-1 ; i++) { 

		spacesout--; 

		innerspaces = innerspaces + 2; 

		for(j=0; j< spacesout; j++) { printf(" "); } 

		printf("/"); 

		for(j=0; j< innerspaces; j++) { printf(" "); } 

		printf("\\\n"); 

	} 

}

void drawA (int size) { 

	int spacesout, innerspaces; 

	int i,j; 

	spacesout = size / 2; 


	for(i=0;i<spacesout;i++) { printf(" "); } 

	printf("/\n"); 


	innerspaces = -1; 

	for(i=1; i<= size/2-1 ; i++) { 

		spacesout--; 

		innerspaces = innerspaces + 2; 

		for(j=0; j< spacesout; j++) { printf(" "); } 

		printf("/"); 

		for(j=0; j< innerspaces; j++) { printf(" "); } 

		printf("\\\n"); 

	}        

} 

void main () {

	drawM(20);
	drawA(20);  

}
