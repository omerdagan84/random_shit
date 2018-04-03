#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main ()
{
	int h=0,m=0,s=0;
	printf("enter time in format of hh mm ss");
	scanf("%d %d %d", &h,&m,&s);
start:
	  for (;h<12;h++) {
		  for (;m<60;m++) {
			  for (;s<60;s++) {
				  printf("%d:%d:%d\n",h,m,s);
				  /*
				  for (double i=0;i<99999999; i++) {
					  i++;
					  i--;
					  */
				  sleep(1);
				  
			  }
			  s=0;
		  }
		  m=0;
	  }  
	  goto start;
}
