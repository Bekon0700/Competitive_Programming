#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>

#include<math.h>
#include<stdio.h>

using namespace std;
int par[5000],rnk[5000],os[5000];


void SINI()
{
    int i=0;

    for(i=1;i<=4000;i++)
    {
        rnk[i]=0;
        par[i]=i;
    }
}


int FS(int u)
{
    if(u != par[u])
        par[u] = FS(par[u]);
    return par[u];
}


void U(int u,int v)
{
    u = FS(u);
    v = FS(v);
    if(rnk[u]>rnk[v])
    {
        par[v]=u;
    }
    else {
        par[u]=v;
        if(rnk[u]==rnk[v])  rnk[v]++;

    }
}

map<string,int>mp;

int main()
{
    //freopen("C.in","r",stdin);
    //freopen(".out","w",stdout);

    int ks=1,tks,i,j,k,n,m,wn,u,v;
    bool tst;
    char a[30],b[30];

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d%d",&n,&m);

        mp.clear();
        SINI();
        memset(os,0,sizeof(os));
        wn=1;

        for(i=0;i<n;i++)
        {
            scanf("%s%s",a,b);

            if(!mp[a])
                u=mp[a]=wn++;
            else    u = mp[a];


            if(!mp[b])
                v=mp[b]=wn++;
            else    v = mp[b];

            U(u,v);
        }
        tst=true;

        for(i=0;i<m;i++)
        {
            scanf("%s%s",a,b);

            if(!mp[a])
                u=mp[a]=wn++;
            else    u = mp[a];


            if(!mp[b])
                v=mp[b]=wn++;
            else    v = mp[b];

            if(tst)
            {
                u = FS(u);
                v=FS(v);


                if(u==v)    tst=false;
//                printf("u:%d v:%d\n",u,v);
//                printf("ou:%d ov:%d\n",os[u],os[v]);
                if(!os[u])
                {
                    os[u]=v;

                    if(os[v])   U(os[v],u);
                    else os[v]=u;

                }
                if(!os[v])
                {   os[v]=u;
                    if(os[u])   U(os[u],v);
                    else os[u]=v;

                }
//                printf("--u:%d v:%d\n",u,v);
//                printf("--ou:%d ov:%d\n",os[u],os[v]);
                if(FS(os[u])!=FS(v))    tst=false;
                if(FS(os[v])!=FS(u))    tst=false;
            }
//            for(j=1;j<6;j++)
//                printf("%d o:%d p: p:%d\n",j,os[j],par[j]);
//            cout<<tst<<endl;
        }


        if(tst)
            printf("Case %d: YES\n",ks++);
        else printf("Case %d: NO\n",ks++);
    }


    return 0;
}
