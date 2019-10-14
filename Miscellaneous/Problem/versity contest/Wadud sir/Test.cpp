#include <stdio.h>
#include <string.h>
#include <math.h>


long long BigMod (long long b,long long p,long long m)
{
    long long x;

    if( p==0 )
        return 1;

    x = BigMod(b,p/2,m);
    x = (x*x) % m;

    if(p%2 != 0)
        x=(x*b)%m;

    return x;
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long b,p,m,x;

    int tks;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&b,&p);
        x=BigMod(b,p,1e9+7);
        printf("%lld\n",x);
    }

    return 0;
}
