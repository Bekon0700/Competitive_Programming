#include<stdio.h>
#include<math.h>

bool f(int a);

int main()
{
    int i,l,n,a,b;

    while(scanf("%d",&n) && n)
    {
        l = n / 2 ;
        a = b = 0 ;
        l++;
        for(i = 3;i<l; i+=2 )
            if( f( i ) )
                if( f( n - i ) )
                {
                    a = i;
                    b = n - i ;
                    break;
                }
        if( a && b )
            printf("%d = %d + %d\n",n,a,b);
        else
            printf("Goldbach's conjecture is wrong.\n");

    }
    return 0;
}

bool f(int a)
{
    int i,j,x;

    x = sqrt(a);
    x ++ ;
    for(i = 3 ; i < x ; i += 2 )
        if( a % i == 0 )
            return false;
    return true;
}

