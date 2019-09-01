#include<stdio.h>
#include<string.h>

const int M = 1000007;
int mm[41][65][65],n;

int gcd(int a,int b)
{
    if(a%b) return gcd(b,a%b);
    return b;
}


int go(int p,int g,int l)
{
    if(!p)
    {
        if(l%g)   return 0;
        return 1;
    }
    int &re = mm[p][g][l],cg;
    if(re>-1)   return re;
    re=0;

    for(int i=1;i<7;i++)
    {
        cg = g*i/gcd(g,i);
        re = (re+go(p-1,cg,(l*10+i)%60))%M;
    }
    return re;
}

int main()
{
    int tks;

    scanf("%d",&tks);
    memset(mm,-1,sizeof mm);

    while(tks--)
    {
        scanf("%d",&n);
        printf("%d\n",go(n,1,0));

    }

    return 0;
}
