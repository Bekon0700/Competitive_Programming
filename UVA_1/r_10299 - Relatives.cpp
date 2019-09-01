#include<stdio.h>
#include<math.h>

bool flag[1000000];
int prime[80000];
void SEIVE();
bool ISPRIME(int x);

int main()
{
	int i,j,k,l,n,x,y,z,p,q,m;
	SEIVE();
	while(scanf("%d",&n)==1 && n)
	{
		z = sqrt(n) + 1 ;
		m = n ;
		p = q = n - 1 ;
		for(i=1;prime[i] < z; i++)
			if( n % prime[i] == 0)
			{
				l = prime[i] - 2 ;	
				x = q / prime[i] ;
				p = p - x + l ;
				while(m % prime[i] == 0 )
					m /= prime[i];
				
			}
		
		q = i;
		
		
		printf("%d\n",p);
	}
	return 0;
}

bool ISPRIME(int x)
{
	if(x==1)
		return false;
	int i,y;
	
	y = sqrt(x) + 1;
	
	for( i = 1 ; prime[i] < y; i++)
		if(x%prime[i]==0)
			return false;
	return true;
}

void SEIVE()
{
	int i,j,k,c=1,x,m = 1000001;
	
	x = sqrt(m) + 1;
	for(i=3;i<m;i += 2 )
		flag[i]=true;
	prime[c++] = 2;
	for(i=3;i<m;i += 2)
		if(flag[i])	
		{
			prime[c++] = i;
			if(i<x)
				for(k = i<<1, j=i*i; j < m; j += k )	
					flag[j] = false ;
			
		}
	
}
