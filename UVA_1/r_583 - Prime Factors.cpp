#include<stdio.h>
#include<math.h>

int prime(int a);

int main()
{
    int m,a,i,j,k,x,b,sign;

    while(scanf("%d",&a)==1 && a)
    {
        printf("%d =",a);
        b=a;
        sign =0;
        if(a<0)
        {
            printf(" -1");
            a *= (-1);
            sign ++;
        }
        if(prime(a))
        {
            if(sign != 0)
                printf(" x");
            printf(" %d\n",a);
            continue ;
        }
        while(a%2==0)
        {
            if(sign != 0)
                printf(" x");
            printf(" %d",2);
            sign ++;
            a /= 2;
        }
        if(prime(a))
        {
            if(sign != 0)
                printf(" x");
            printf(" %d\n",a);
            continue ;
        }

        for(i = 3 ; a != 1 ; i += 2)
        {
            if( a % i == 0)
            {
                if(prime(i))
                {
                    a /= i;
                    if(sign != 0)
                        printf(" x");
                    printf(" %d",i);
                    sign ++;
                    i -= 2;

                    if(prime(a) && a != 1 )
                    {
                        printf(" x %d",a);
                        break ;

                    }
                }
            }

        }
        printf("\n");
    }
    return 0;
}

int prime(int a)
{
    int x,i,j;

    if(a == 1)  return 0 ;
    if(a==2)    return 1 ;
    if(a%2 == 0)    return 0;
    x=sqrt(a);
    x++;
    for( i = 3 ; i < x ; i += 2)
        if( a % i == 0 )    return 0;

    return 1;
}
