#include<stdio.h>

int main()
{
    long long r,p,ks=1,rr;

    while(scanf("%lld",&r)==1&&r)
    {
        p=6*r;
        rr=r*r;
        printf("Case %lld: %lld %lld %lld %lld %lld\n",ks++,p,p*r,8*rr,2*rr,32*rr*rr);
    }

    return 0;
}
