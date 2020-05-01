#include<stdio.h>
#include<math.h>

int main()
{
	double a,b,pi=2*acos(0),d,x;
	
	d=pi/20;
	x = sin(12 * d) / sin(7 * d);
	while(scanf("%lf",&a)==1)
	{
		b = a * x ; 
		printf("%.10lf\n",b);
	}
	return 0 ;
}
