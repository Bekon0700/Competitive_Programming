#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int  d[2000], prime[4700] ;
bool  flag[45000] ;
bool isprime(int n);
void SEIVE();

int main()
{
	int  i, j, k, l,nd, c, r, x, N, y, z, t ; 
	
	SEIVE();
	scanf("%d",&t);
	
	t++;
	for(k = 1 ; k < t; k++)
	{
		scanf("%d%d",&c,&r);
		printf("Case #%d:",k);
		if(c==r)
		{
			printf(" 0\n");
			continue;
		}
		nd = 0 ;
		x = c - r ;
		
		if(isprime(x))
		{
			if(1 > r)
				printf(" 1");
			if(x > r && x != 1)
				printf(" %d",x);
			printf("\n");
			continue ;
		}
		
		N = sqrt(x) + 1;
		z = x ;
		d[nd++] = 1 ;
		for(i=2; i < N; i++ )
			if( z % i == 0)
			{
				d[nd++] = i ;	
				
				if(x/i > i)				
					d[nd++] = x/i ;	
				
			}
		sort(&d[0],&d[nd]);
			
		d[nd++]=z;
		
		for(i=0; i< nd; i++)
			if(d[i] > r)
			printf(" %d",d[i]);
		printf("\n");
	}
	return 0;
}

bool isprime(int n)
{
	int i,j,x;
	if(n==2)	return true;
	if(n%2==0)	return false;
	if(n < 44000)	return flag[n];
	x = sqrt(n) + 1 ;	
	for(i=1;prime[i] < x ;i++)
		if(n % prime[i] == 0 )
			return false;
	return true;
}
void SEIVE()
{
	int i,j,k,r,x,c=1,m=45000;
	flag[1] = true;	
	for(i=3;i<m;i += 2 )	flag [i] = true ;
	x=sqrt(45000)+1;
	for(i=3;i<m;i += 2 )
		if(flag[i])
		{
			prime[c++]	= i;
			if(i<x)
			{
				for(j = i*i,r =i<<1 ;j<m;j+=r)
					flag[j] = false;
			}
			
		}
		
}
/*
spasel input:
1 0
*/
