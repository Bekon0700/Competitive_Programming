#include<stdio.h>

int main()
{
    int n,d,f,a,b,c,i;

    while(scanf("%d%d",&n,&d)==2)
    {
        a = n / d ;
        printf("[%d;",a);
        i=0;
        b=n;
        n=d;
        d = b - ( a * d );
        while( n != 1 )
        {
            a = n / d ;
            if(i)
                printf(",");
            printf("%d",a);
            i=0;
            b=n;
            n=d;
            d = b - ( a * d );
            i ++ ;
        }
        printf("]\n");


    }

    return 0;
}
//[2;3,1,4]
