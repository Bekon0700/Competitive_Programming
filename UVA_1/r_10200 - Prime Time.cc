#include<stdio.h>
#include<math.h>

#define SIZE_N 1000000
#define SIZE_P 80000

int s[10009];
int flag [SIZE_N] ;
int prime [SIZE_P] ;

bool ISPRIME(int x)
{
	if(x<1000000)	
		return flag[x];
	int a,i;
	a=sqrt(x)+1;
	for(i=2;prime[i] < a ;i++)
		if(x%prime[i]==0)
			return false;
	return true;
}
void gen()
{
	for(int i=0,k=0; i < 10002;i++)	
	{
		if( ISPRIME( i*i + i + 41 ) )	
			k++;
		s[i]=k;		
	}
}

void MAIN()
{
	int a,b,j,k;
	double x;
	
	gen();
	while(scanf("%d%d",&a,&b)==2)
	{
		j= b - a + 1;
		k = s[b] - s[a] ;
		if(ISPRIME(a*a+a+41))
			k++;
		x = k * 100 ;
		x /= j;
		printf("%.2lf\n",x + 1e-5);
	}
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
int main()
{
	seive();
	MAIN();
	return 0;
}
