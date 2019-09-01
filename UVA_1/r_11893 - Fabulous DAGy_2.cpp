#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>adj[400];
int col[400],dis[400],K=0,par[400],id[400],from[400],I;

int DFS(int u)
{
    if(K)   return -3;
    col[u]=1;

    int x;
    for(int i=0;i<(int)adj[u].size();i++)
    {
        if(adj[u][i]==I)    continue;
        if(col[adj[u][i]]==1)
        {
            //printf("DFS: u:%d adj:%d\n",u,adj[u][i]);
            K=1;return -3;
        }
        else
        {
            if(col[adj[u][i]]==0)
            {
                x = DFS(adj[u][i]);
                if(dis[u]<x+1)
                {
                    dis[u] = x+1;
                    par[u] = adj[u][i];
                }
            }
            else if(col[adj[u][i]]==2)
            {
                if(dis[u]<1+dis[adj[u][i]])
                {
                    dis[u] = dis[adj[u][i]]+1;
                    par[u] = adj[u][i];
                }
            }
        }
    }
    col[u]=2;
    if(K)   return -3;
    return dis[u];
}


int main()
{
    int i,u,v,n,m,T,l;
    bool tst;

    //freopen("in.in","r",stdin);

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(id,0, sizeof id);

        for(i=0;i<n;i++)    adj[i].clear();



        while(m--)
        {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            id[v]++;
            from[v]=u;
        }


        tst=true;
        for(i=0;i<n && tst;i++)
            if(id[i]==1)
            {
                memset(par,-1,sizeof par);
                memset(dis,0,sizeof dis);
                memset(col,0,sizeof col);
                K=0;
                I=i;
                if(DFS(i)<n-1 || K)
                {
                    //printf("i:%d dis:%d  K:%d\n",i,dis[i],K);
                    continue;
                }

                l = i;

                while(par[l]!=-1)   l = par[l];

                if(from[i]==l)  tst=false;
            }

        if(!tst)    printf("Yeah, I'm superman\n");
        else printf("Your DAGy was initially defected!\n");
    }

    return 0;
}


