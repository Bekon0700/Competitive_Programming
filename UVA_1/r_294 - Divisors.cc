#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int  d[2000], prime[4700] ;
bool  flag[45000] ;
void SEIVE();

int main()
{
	int  i, j, k, l, max, mf, u, x, y , d, U , N, t ; 
	
	SEIVE();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&l,&u);	
		U = u + 1 ;
		max = l;
		mf = 1;
		for( i = l ; i < U ; i ++ )
		{
			y = i ;
			N = sqrt(y) + 1 ;
			d = 1 ;
			
			for( j = 1 ; prime[j] < N ; j ++ )
				if( y % prime[j] == 0 )
				{
					x=1;
					while(y%prime[j] == 0)
					{
						x++;
						y /= prime[j] ;
					}
					d *= x;
					N = sqrt(y) +1 ;			
				}
			if(y != 1)	
				d *= 2;
			if(d > mf)
			{
				max=i;
				mf = d;				
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",l,u,max,mf);
	}
	
	
	return 0;
}


void SEIVE()
{
	int i,j,k,r,x,c=1,m=45000;
	flag[1] = true;	
	prime[c++] = 2;
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
