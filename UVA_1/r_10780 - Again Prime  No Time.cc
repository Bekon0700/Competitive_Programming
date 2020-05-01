#include<stdio.h>
#include<math.h>

#define max 5010
bool flag[5010];
int prime[900];

void SEIVE();
bool ISPRIME(int x);

int main()
{
	int  i,j,k,x,y,min,t=0,z,p,q,M,m,n,T;
	
	SEIVE();
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d%d",&m,&n);
		t ++ ;
		printf("Case %d:\n",t);
		if( ISPRIME( m ) )
		{
			if( n < m )
			{
				printf("Impossible to divide\n");	
				continue;
			}
			y = 0 ;
			while( n )
			{
				y += (n/m);
				n /= m;
			}
			min = y;
		}
		else
		{	
			min = 100000;			
			M = sqrt(m) + 1 ;			
			for(i=1; prime[i]< M ; i ++ )
				if(m % prime[i] == 0)
				{
					j=0;
					while( m % prime[i] == 0)
					{
						m /= prime[i];
						j ++ ;
					}
					M = sqrt(m) + 1 ;
					p = n ;
					y = 0 ;
					while(p)
					{
						y += (p/prime[i]) ;
						p /= prime[i];
					}
					q = y / j;
					
					if( q < min)
						min = q ;
					
				}
			if( m > 1 )
			{
				if( n < m )
				{
					printf("Impossible to divide\n");	
					continue;
				}
				y = 0 ;
				while(n)
				{
					y += (n/m);
					n /= m;
				}
				if( y < min )
					min = y ;
			}
		}
		printf("%d\n",min);
	}
	return 0;
}

void SEIVE()
{
	int x,c=1,i,j,r;
	
	prime[c++] = 2 ;
	for(i=3;i<max;i+=2)
		flag[i] = true;
	x = sqrt(max) + 1 ;
	for(i=3;i<max; i += 2 )
		if(flag[i])
		{
			prime[c++] = i ;
			if(i<x)
			{
				for(j = i*i , r = i << 1 ; j < max; j += r)
					flag[j]=false;
			}
		}
	
}
bool ISPRIME(int x)
{
	int i,y;
	
	y = sqrt( x ) + 1;
	for( i = 1 ; prime[i] < y; i ++ )
		if( x % prime[i] == 0 )
			return false;
	return true;
}
