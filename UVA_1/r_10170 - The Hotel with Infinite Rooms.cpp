#include<stdio.h>
#include<math.h>

int main()
{
    long long s,d,a,n;
    double x,y,z;

    while( scanf("%lld%lld",&s,&d) == 2 )
    {
        a = s * ( s - 1) / 2 ;
        z = a + d ;
        x = sqrt( 8 * z + 1) ;
        y = ceil(x);
		 
        y -- ;
        y /=2 ;
		y = ceil(y);
        printf("%.0lf\n",y);
    }

    return 0 ;
}
