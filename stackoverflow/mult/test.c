#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	int x,y,mul=0,n;
	int sign = 0;

	cout<<"Enter the two numbers";
	cin>>x>>y;
	int m;
	cout<<"x:"<<x<<endl;
	cout<<"y:"<<y<<endl;
	cout<<"Result of Addition:"<<x+y<<endl;
	cout<<"Result of subtraction:"<<x+(-y)<<endl;
	
	/* verify the sign of the expected result */
	if ( (x < 0 && y < 0) || ( x > 0 && y > 0) )
	{
		sign = 1;//positive
	} else if ( (x > 0 && y < 0) && (x < 0 && y > 0) )  {
		sign = 0;//negative
	} else if ( x == 0 || y == 0 ) {
		sign = -1;//zero
	}	

	/* multiply the numbers regardless of the result */
	n=abs(x);
	m=abs(y);
	for(int i=0;i<n;i++)
	{
		mul=mul+m;
	}

	/*assign the correct sign to the calculated result */
	if (sign == 1) 
		cout<<"Result of multiplication:"<<mul<<endl;
	else if ( sign == 0)
		cout<<"Result of multiplication:"<<0-mul<<endl;
	else if ( sign == -1 )
		cout<<"Result of multiplication:"<<0<<endl;

	return 0;
}
