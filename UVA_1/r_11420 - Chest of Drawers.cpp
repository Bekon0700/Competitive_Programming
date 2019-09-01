#include<stdio.h>
#include<string.h>


long long mm[67][67][2];

long long go(int n,int m,int l)
{
    if(n<m || m<0)     return 0;
    if(n==0)    return 1;

    long long &re= mm[n][m][l];
    if(re>-1)   return re;

    re = go(n-1,m-(l==1),1)+go(n-1,m,0);

    return re;
}

int main()
{
    int n,m;

    memset(mm,-1,sizeof mm);

    while(scanf("%d%d",&n,&m)==2 && n>0)
    {
        printf("%lld\n",go(n,m,1));
    }
    return 0;
}
