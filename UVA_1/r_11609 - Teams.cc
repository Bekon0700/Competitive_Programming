#include<stdio.h>


int f(int n);

int main()
{
	long long n,t,x,i;
	
	scanf("%lld",&t);
	++ t;
	for(i=1;i<t;i++)
	{
		scanf("%lld",&n);
		
		x = (n * f( n - 1 )) % 1000000007 ;	
		
		printf("Case #%lld: %lld\n",i,x);
	}
	return 0;
}

int f(int p)
{
	long long x = 1,m = 1000000007, i, pow = 2 ;
	
	while(p)
	{
		if( p % 2 )	
			x = ( x * pow ) % m;
		pow = ( pow * pow ) % m ;
		p >>= 1;
	}
	return x;	
}
