#include<stdio.h>

#define SIZE_N 1000113
#define SIZE_P 78503

bool flag [SIZE_N] ;
int prime [SIZE_P] ;
int dff[SIZE_P];
int R[SIZE_N];

void seive ();

int main()
{
    int  i, j, kr, x[120], m, u, l, n ;
    bool  b ;

    seive () ;
    scanf("%d",&kr) ;

    while(kr -- >0)
    {
		for( i = 1 ; i < 117 ; i ++ )	x[i] = 0 ;
		scanf("%d%d",&l,&u);
		
        while( flag[l] != true && l < u)	l ++ ;
		j = R[l];
		if(!j)	
		{
			printf("No jumping champion\n");			
			continue ;	
		}
		while(prime[++j] <= u)	x[dff[j-1]] ++ ;	
		b = false ;	
		m=0;
		for( i = 1 ; i < 116 ; i ++)	
			if( x[i] >= m )
			{
				if( x[i] > m )
				{
					m = x[i];	
					b = true ;
					n = i ;
				}
				else
					b = false ;
			}
		if( b )		
			printf("The jumping champion is %d\n",n);
		else
			printf("No jumping champion\n");			
	}
    return 0;
}

void seive ()
{
	int i, j, r, c = 0,p,d=0 ,re=1;

	for(i=1;i<1000000; i++)		R[i] = 0 ;
    flag[0] = flag[1] = false ;
	for ( i = 3; i <= SIZE_N; i += 2 )  flag[i] = true ;
	flag [2] = true ;
	prime [++c] = 2 ;
	R[2]=1;
	p=SIZE_N+1;
	for ( i = 3; i <p; i += 2 )
	{
		if ( flag[i] )
		{
			prime[++c] = i ;
			re ++;
			R[i]= re;
            dff[++d] = prime[c] - prime[c-1];
            if ( SIZE_N / i >= i )
            {
                r = i * 2 ;
                for ( j = i * i; j <p; j += r )
                    flag[j] = false ;
            }
		}
	}
	flag[1000000] =  true ;
}
