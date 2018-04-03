#include <stdio.h>
static int var = 100;
void foo(){
	static int var = 200;
	printf("\n Var:%d - %p\n", var, &var);
	
}
void main()
{
	foo();
	printf("\n Var:%d - %p\n", var, &var);
}
