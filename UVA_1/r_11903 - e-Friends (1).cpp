#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define p2(a)   (1<<a)

bool en[14][14];
int mm[1<<13][13][12],n,way[15];

int go(int msk,int l,int v)
{
    if(msk==p2(n)-1)    return 1;

    int &re=mm[msk][l][v];
    if(re != -1)  return re;

    re=0;
    for(int i=0;i<n;i++)
        if((msk&p2(i))==0)
        {
            if(en[l][i])
            {
                if(v)   re+=go(msk|p2(i),i,v-1);
            }
            else re+=go(msk|p2(i),i,v);
        }
    return re;
}

int main()
{
    int T,ks=1,i,t,k,u,q;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d%d",&n,&k,&q);
        memset(en,false,sizeof en);

        for(i=0;i<n;i++)
        {
            scanf("%d",&t);

            while(t--)
            {
                scanf("%d",&u);
                en[i][--u]=true;
            }
        }

        printf("Case %d:\n",ks++);

        memset(mm,-1,sizeof mm);
        memset(way,-1,sizeof way);

        while(q--)
        {
            scanf("%d",&t);
            if(k)   t/=k;
            else t=n-1;

            t = min(n-1,t);

            if(way[t]==-1)  way[t] = go(0,n,t);

            printf("%d\n",way[t]);

        }
    }
    return 0;
}

