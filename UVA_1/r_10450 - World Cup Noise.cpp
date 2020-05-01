#include<stdio.h>

int main()
{
    long long a=2,b=1,i,k,fib[55];

    fib[0] = 0 ;
    fib[1] = 2 ;

    for(i=2;i<51;i++)
    {
        fib[i] = b + a ;
        b = a ;
        a =fib[i];
    }
    scanf("%lld",&k);
    for(i = 0; i < k; i++)
    {
        scanf("%lld",&a);
        printf("Scenario #%lld:\n%lld\n\n",i+1,fib[a]);

    }
    return 0 ;
}
