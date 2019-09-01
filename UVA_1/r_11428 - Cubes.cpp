#include<stdio.h>
#include<math.h>

int main()
{
	long long  d,b,c,a, i, j, x, y, n,k ;
	double r = 3;

    while( scanf("%lld",&n) == 1 && n )
	{
		x = pow(n,(1/r));
		a = pow(x,3);
		b = a - n ;
		if( b > -1 )
		{
			y = pow(b,(1/r));
			c = pow(y,3);
			d = a - c ;
		}
		else
			d = n + 1 ;
		i=0;
		printf("\t\t\t%lld %lld\n",x,y);
		while( d != n )
		{
			x ++ ;
			a = pow(x,3);
			b = a - n ;
			y = pow(b,(1/r));
            c = pow(y,3);
			d = a - c ;
			if(d==n)    break;
            y++;
            c = pow(y,3);
			d = a - c ;
			i++;
			//printf("     %d\n",i);
			//if(i>2)break;
			if( pow(x,3) - pow( (x-1),3 ) > n )     break ;
		}
		if(d == n)
			printf("%lld %lld\n",x,y);
		else
			printf("No solution\n");
	}

	return 0 ;
}
