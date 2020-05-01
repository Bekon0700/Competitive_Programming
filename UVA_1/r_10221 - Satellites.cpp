#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    double  s,a,x,y, pi = 2 * acos(0) ;
    char A[4];

    while(scanf("%lf%lf%s",&s,&a,A) == 3)
    {
        if( strcmp(A,"deg") == 0 )
            a *= 60 ;
		if( a > 10800)	a = 21600 - a ;
        s += 6440 ;
        y =  pi * s * a / 10800 ;
        a /= 2 ;
        a = a * pi / 10800 ;
        x = 2 * s * sin(a) ;
        printf("%.6lf %.6lf\n",y,x) ;
    }

    return 0 ;
}
