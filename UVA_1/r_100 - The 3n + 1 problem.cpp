#include<stdio.h>

long long a[1000000];

int main()
{
    long long i,j,k,x,y,n,m;
    bool c[1000000];

    for(i=1;i<1000000;i++)  c[i] = true ;
    for(i=1;i<1000000;i++)
        if(c[i])
        {
            x=1;
            n=i;
            while(n != 1)
            {
                if(n & 1) n = 3 * n + 1 ;
                else    n >>= 1 ;
                if( n < 1000000 && !c[n] )
                {
                    x += a[n] ;
                    break ;
                }
				x ++ ;
            }
            for(j = i ; j <1000000; j <<= 1, x++ )
            {
                a[j] = x ;
                c[j] = false ;
            }
        }
    while(scanf("%lld%lld",&x,&y)==2)
    {
        printf("%lld %lld",x,y);
        if(y<x)
        {
            n=x;
            x=y;
            y=n;
        }
        n=1;
        for(;x<=y;x++)
            if(a[x]>n)
                n=a[x];
        printf(" %d\n",n);
    }
    return 0;
}
