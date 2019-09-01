#include<stdio.h>

int main()
{
 	char m,mm,z='0';
	double x,y,a,b,h;

	while(scanf("%lf:%c%c",&h,&m,&mm)==3 )
	{
		if(h == 0 && mm == 48 && m == 48)	break ;

		b = 10 * ( m - 48) + ( mm - 48) ;
		a = ( b + h * 60) / 2;
		b = 6 * b ;

		if(a>b)	x = a - b ;
            else   x= b - a ;
		if(x>180)	x = 360 - x ;
		printf("%.3lf\n",x);
	}

	return 0 ;
}
