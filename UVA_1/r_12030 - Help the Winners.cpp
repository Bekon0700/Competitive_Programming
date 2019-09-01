#include<stdio.h>
#include<string.h>

#define  p(i)    (1LL<<i)

long long mm[p(15)+2][2],f[16];
int n;
int mat[15][15];

long long go(int msk,int c,int l)
{
    if(msk==p(n)-1 && l) return 1;

    long long &re=mm[msk][l];

    if(re>-1)   return re;
    re=0;
    if(l==1)
    {
        for(int i=0;i<n;i++)
            if(0 == (msk&p(i)) && mat[c][i]==1)
                re+=go(msk|p(i),c+1,l);
    }
    else
    {
        for(int i=0;i<n;i++)
            if(0 == (msk&p(i)))
            {
                if(mat[c][i]==2) re+=f[n-c-1];
                else re+=go(msk|p(i),c+1,0);
            }
    }

    return re;
}


int main()
{
    int ks=1,tks,i,j;

    for(f[0]=1,i=1;i<16;i++)    f[i] = i*f[i-1];

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",mat[i]+j);

        memset(mm,-1,sizeof mm);

        printf("Case %d: %lld\n",ks++,go(0,0,1)+go(0,0,0));
    }

    return 0;
}




