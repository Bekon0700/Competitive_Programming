#include<stdio.h>

int main()
{
	long long  n, x, i = 1, j,z9, z1;

	while( scanf("%lld",&n) == 1 )
	{
		printf("%4lld.",i++);
		if(!n)
		{
			printf(" 0\n");	
			continue;
		}
		z9 = 99999999999999LL;
		z1 = 100000000000000LL ;
		j = 0 ;
		if(n > z9 )
		{
			x = n / z1 ;
			n  %=  z1 ;
			printf(" %lld kuti",x);
			if( !n )
			{
				printf(" kuti\n");
				continue;
			}
			else	j=1;
		}
		z9 /= 100 ; z1 /= 100 ;
		if(n > z9 )
		{
			x = n / z1 ;
			n  %=  z1 ;
			printf(" %lld lakh",x);
			if( !n )
			{
				printf(" kuti\n");
				continue;
			}
			else	j=1;
		}
		z9 /= 100 ; z1 /= 100 ;
		if(n > z9 )
		{
			x = n / z1 ;
			n  %=  z1 ;
			printf(" %lld hajar",x);
			if( !n )
			{
				printf(" kuti\n");
				continue;
			}
			else	j=1;
		}
		z9 /= 10 ; z1 /= 10 ;
		if(n > z9 )
		{
			x = n / z1 ;
			n  %=  z1 ;
			printf(" %lld shata",x);
			if( !n )
			{
				printf(" kuti\n");
				continue;
			}
			else	j=1;
		}
		z9 /= 100 ; z1 /= 100 ;
		if(n > z9 )
		{
			j = 0 ;
			x = n / z1 ;
			n  %=  z1 ;
			printf(" %lld kuti",x);
		}
		if(j)	printf(" kuti");

		if(n > 99999 )
		{
			x = n / 100000 ;
			n  %=  100000 ;
			printf(" %lld lakh",x);
		}
		if(n > 999 )
		{
			x = n / 1000 ;
			n  %=  1000 ;
			printf(" %lld hajar",x);
		}
		if(n > 99 )
		{
			x = n / 100 ;
			n  %=  100 ;
			printf(" %lld shata",x);
		}
		if(n)	printf(" %lld",n);
		printf("\n");

	}
	return 0;
}
