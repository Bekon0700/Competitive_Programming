#include<stdio.h>
#include<math.h>

int GCD(int a,int b);

int main()
{
    int a[52],i,j,k,n,m,x,y;
    double  A,B,C;

    while(scanf("%d",&n)==1 && n != 0)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        x = 0 ;
        for(i = 0 ; i < n ; i ++ )
            for(j = i + 1 ; j < n ; j ++ )
                if(GCD(a[i],a[j]) == 1)
                    x ++ ;
		
        if( x == 0 )
        {
            printf("No estimate for this data set.\n") ;
            continue ;
        }
        B = n ; n-- ;B *= n ; B/= 2 ;
		
        A = 6 * B / x ;
        C = sqrt(A) ;
        printf("%.6lf\n",C);

    }

    return 0 ;
}

int GCD(int a,int b)
{
    int c;
    if(b>a)
    {
        c = a ;
        a = b ;
        b = c  ;
    }
    c = 1;
    while( c != 0)
    {
        c = a % b ;
        a = b ;
        b = c ;
    }
    return a ;
}
