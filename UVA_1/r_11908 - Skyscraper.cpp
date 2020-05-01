#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
typedef struct {int l,h,c;}O;

O o[30002];
int dp[500002];

bool com(O a,O b)
{
    if(a.l==b.l)    return a.h<b.h;
    return a.l<b.l;
}


int main()
{
    int t,ks=1,n,i,j,m;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&o[i].l,&j,&o[i].c);
            o[i].h=o[i].l+j-1;
        }
        memset(dp,-1,sizeof dp);
        m=0;

        sort(o,o+n,com);

        dp[o[0].l]=0;
        dp[o[0].h+1]=o[0].c;
        m>?=o[0].c;

        for(i=1;i<n;i++)
        {
            for(j=o[i-1].l;j<=o[i].l;j++)
                dp[o[i].l]>?=dp[j];
            dp[o[i].h+1]>?=dp[o[i].l]+o[i].c;
            m>?=dp[o[i].h+1];
            //cout<<m<<endl;
        }
        printf("Case %d: %d\n",ks++,m);
    }
    return 0;
}
