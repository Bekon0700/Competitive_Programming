#include<stdio.h>
#include<string.h>


typedef long long LL;
const LL si=105, M = 1000000;

LL mm[si][si];

LL go(int N,int K)
{
    if(N==0)    return 1;
    if(K==0)    return 0;
    LL &re = mm[N][K];
    if(re>-1)   return re;

    re = go(N-1,K) + go(N,K-1) ;
    re%=M;

    return re;
}


int main()
{
    int n,k;

    memset(mm,-1,sizeof mm);

    while(scanf("%d%d",&n,&k)==2 && (n||k))

        printf("%lld\n",go(n,k));


    return 0;
}
