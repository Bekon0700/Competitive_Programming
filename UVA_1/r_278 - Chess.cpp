#include<stdio.h>

int main()
{
    int x,m,n,N,i=0;
    char a[2];

    scanf("%d",&N);
    while(i<N)
    {
        scanf("%s%d%d",a,&n,&m);
        switch(a[0])
        {
            case 'Q':   if( n > m )
                            printf("%d\n",m);
                        else
                            printf("%d\n",n);
                        break;
            case 'K':   n = ( n + 1 ) / 2 ;
                        m = ( m + 1 ) / 2 ;
                        x = n * m;
                        printf("%d\n",x);
                        break ;

            case 'k':   x = n * m + 1 ;
                        x /= 2 ;
                        printf("%d\n",x);
                        break ;
            case 'r':   if( n > m )
                            printf("%d\n",m);
                        else
                            printf("%d\n",n);
                        break;

        }
        i++;
    }
    return 0;
}
