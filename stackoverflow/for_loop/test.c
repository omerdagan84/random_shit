#include<stdio.h>
int main(){
	int i,x,c,r,size;
	int wa[10];
	size=0;
	for(i=0;i<10;i++){
		wa[i]=0;
	}
	while((c=getchar())!=EOF){
		switch(c){
			case' ':{
						wa[size]++;
						size=0;
						break;}
			case'\n':{
						 wa[size]++;
						 size=0;
						 break;}
			case'\t':{
						 wa[size]++;
						 size=0;
						 break;}
			default:{
						size++;
						break;
					}
		}
	}

	for(r=0;r<=10;++r){
		printf("%d",r);
		for(x=0;x<wa[r];x++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
