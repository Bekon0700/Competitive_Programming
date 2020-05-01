#include<stdio.h>
#include<string.h>

int mm[1001][1001];

int go(int n,int p)
{
    if(p<2)  return p;
    if(p>n) return 0;

    int &re=mm[n][p];

    if(re>-1)   return re;
    re = go(n-1,p-1)+go(n-1,p) ;
    re = re*p;

    return re;
}

int main()
{
    int tks,ks=1,n,i,sum;

    memset(mm,-1,sizeof mm);

    for(i=0;i<=1000;i++)
        go(1000,i);

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d",&n);
        for(sum=i=0;i<n;i++)
            sum= sum+go(n,i+1);
        printf("%d\n",sum);
    }

    return 0;
}
