#include<stdio.h>

#define SIZE_N 10099
#define SIZE_P 1257

int flag [SIZE_N] ;
int prime [SIZE_P] ;

void seive ();
int main()
{
	seive();
	int i,j,k,n,t,max,num,p,N;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);	
		N = n + 1;
		max = 0;
		for(i=1;prime[i]<N;i++)
		{
			p = n/prime[i];	
			k = n - prime[i] * p;
			if(k>max)			
			{
				max = k;
				num = prime[i];				
			}
		}
		printf("%d\n",num);
		
	}
	return 0;
}
void seive ()
{
	int i, j, r, c = 0,p ;

	for ( i = 3; i <= SIZE_N; i += 2 )  flag[i] = true ;

	flag [2] = true ;
	prime [++c] = 2 ;
	p=SIZE_N+1;
	for ( i = 3; i <p; i += 2 )
	{
		if ( flag[i] )
		{
			prime[++c] = i ;

            if ( SIZE_N / i >= i )
            {
                r = i * 2 ;
                for ( j = i * i; j <p; j += r )
                    flag[j] = false ;
            }
		}
	}
}
