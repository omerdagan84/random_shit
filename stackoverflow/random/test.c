#include <stdio.h>
#include <string.h>

int main(){

	char test[6]; //your test array is of fixed size + 1 for the '\0' char
	char result[6]; //if you use a pointer you must malloc the array - but in this case use static allocation it is easier
	int i,e = 0;
	int ch;

	while((ch = getchar()) != '\n'){
		if(e < 5){
			test[e]=ch; //no need for pointer here
			e++;
		}
	}
	test[e] = '\0'; //null terminator at the end of the string

	printf("%s", test);
	for(i =0; i < 5; i++){
		if ( test[i] == 'A' || test[i] == 'B' ||test[i] == 'C' )
			result[i] = '2';
		else if ( test[i] == 'D' || test[i] == 'E' ||test[i] == 'F' )
			result[i] = '3';
	}
	result[5] = '\0'; //add the null terminator

	/*	if(strcmp(test++,"A") == 0 || strcmp(test++,"B")==0 || strcmp(test++,"C")==0){
			result[i] = "2";
		}else if (strcmp(test++,"D") == 0 || strcmp(test++,"E")== 0 || strcmp(test++,"F")== 0){
			result[i] = "3";
		}
	}
	*/

	/* you can just print the string no need for a loop here 
	for(i = 0; i<5;i++){
		printf("%s", result[i]);
	}
	*/
	printf("%s", result);
	return 0;
}
