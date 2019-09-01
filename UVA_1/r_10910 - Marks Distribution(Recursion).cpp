#include<stdio.h>
#include<string.h>


typedef long long LL;
const int si=105, M = 1000000;

LL mm[si][si];

LL go(int N,int K)
{
    if(N==0)    return 1;
    if(K==0)    return 0;
    LL &re = mm[N][K];
    if(re>-1)   return re;

    re = go(N-1,K) + go(N,K-1) ;

    return re ;
}


int main()
{
    int n,t,p,tks;

    memset(mm,-1,sizeof mm);

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d",&n,&t,&p);

        printf("%lld\n",go(t-n*p,n));
    }

    return 0;
}

