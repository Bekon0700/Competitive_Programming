#include<stdio.h>
#include<math.h>

#define SIZE_N 46341
#define SIZE_P 4800

int flag [SIZE_N] ;
int prime [SIZE_P] ;

bool pr(int x);
void seive ();


int main()
{
 	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int  lep = 4793, f , n, i, j, k, x, y, m, p, q ;
    bool g;
	
    seive();
    while(scanf("%d%d",&f,&n) == 2 )
    {
        if(n == 0)
        {
            printf("%d does not divide %d!\n",n,f);
            continue ;
        }
		if(n <= f)
        {
            printf("%d divides %d!\n",n,f);
            continue ;
        }
		
		if(n == 1 && f == 0)
        {
            printf("%d divides %d!\n",n,f);
            continue ;
        }
        if( pr(n) )
        {
            printf("%d does not divide %d!\n",n,f);
            continue ;
        }
		k = n;
		g = true;
		for( i = 1 ; prime[i] <= f && i < lep && k > 1;i++)
		{
			if( k % prime[i] == 0)
			{
				m = 0 ;
				while( k % prime[i] == 0 )
				{
					k /= prime[i] ;
					m++;
				}
				x = 0 ;
				y = f ;
				y /= prime[i];
				while( y != 0 && x < m)
				{
					x += y ;
					y /= prime[i];
				}
				//printf("x:%d  m:%d",x,m);
				//printf("i: %d  k:{ %d }\n",prime[i],k);
				if( x < m)
				{
        		    printf("%d does not divide %d!\n",n,f);
					g = false ;
            		break ;
        		}
				//printf("\ti: %d  k:{%d}\n",prime[i],k);
			}
			
		}
		//printf("\tk:{%d}\n",k);		
			
		if(g)	
		{
        	if( k == 1 || k <= f )
				printf("%d divides %d!\n",n,f);
			else
				printf("%d does not divide %d!\n",n,f);
		}
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

bool pr(int x)
{
    for(int i=1 ; prime[i] < x && i < 4793 ;i++)
        if( x % prime[i] == 0) return false;
    return true ;
}
