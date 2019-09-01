#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

const int NV = 1001;

vector<int>adj[NV],en[NV],bridge,ord;
int L[NV],H[NV],ND[NV],VN[NV],cnt;
int ED[NV*NV][2];
bool f[NV*NV];
int f2[NV*NV];

void DFS(int u)
{
    L[u]=H[u]=VN[u] = cnt++;
    ND[u]=1;


    for(int v,i=0;i<(int)adj[u].size();i++)
    {
        if(!f[en[u][i]]) continue;

        f[en[u][i]] = false;
        v = adj[u][i];
        if(L[v]==-1)
        {
            DFS(v);

            ND[u]+=ND[v];
            L[u] = min(L[u],L[v]);
            H[u] = max(H[u],H[v]);

            /// Decide the Bridge

            if(L[v]>=VN[v] && H[v]<VN[v]+ND[v])
                bridge.push_back(en[u][i]);
            else
            {
                printf("%d %d\n",u,v);
                f2[en[u][i]] = 1;
                en[u][i]=-1;
            }

        }

        L[u] = min(L[u],VN[v]);
        H[u] = max(H[u],VN[v]);
    }
    ord.push_back(u);
}


void DFS1(int u)
{
    L[u]=1;

    for(int v,i=0;i<(int)adj[u].size();i++)
    {
        v = adj[u][i];

        if(L[v]==-1 && en[u][i]!=-1 && f2[en[u][i]]<2)
        {
            if(!f2[en[u][i]])
            {
                printf("%d %d\n",v,u);
                f2[en[u][i]] = 1;
            }

            DFS1(v);
        }
    }
}

void Find_Bridges()
{
    memset(L,-1,sizeof L);
    bridge.clear();
    ord.clear();

    cnt=0;
    DFS(1);

    reverse(ord.begin(),ord.end());

    for(int i=0;i<(int)bridge.size();i++)
    {
        f2[bridge[i]] = 2;
        printf("%d %d\n",ED[bridge[i]][0],ED[bridge[i]][1]);
        printf("%d %d\n",ED[bridge[i]][1],ED[bridge[i]][0]);
    }

    memset(L,-1,sizeof L);

    for(int i=0;i<(int)ord.size();i++)
        if(L[ord[i]]==-1)
            DFS1(ord[i]);

}


int main()
{
    //freopen("in.in","r",stdin);

    int i,u,v,n,m,ks=1;

    while(scanf("%d%d",&n,&m)==2 && (n||m))
    {
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
            en[i].clear();
        }

        memset(f,true,sizeof f);
        memset(f2,0,sizeof f2);

        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);

            ED[i][0]=u;
            ED[i][1]=v;

            adj[u].push_back(v);
            adj[v].push_back(u);
            en[u].push_back(i);
            en[v].push_back(i);
        }


        printf("%d\n\n",ks++);


        Find_Bridges();


        for(i=0;i<m;i++)
            if(!f2[i])
                printf("%d %d\n",ED[i][0],ED[i][1]);

        printf("#\n");
    }
    return 0;
}



