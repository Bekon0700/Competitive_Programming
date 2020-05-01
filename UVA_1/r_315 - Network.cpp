#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

#define V 105
int cnt,num[V],low[V],par[V],n;
bool isar[V];
vector<int>vi[V];

char a[100000];

void DFS(int u)
{
    int i,chi=0,v;
    num[u] = low[u] = cnt++ ;

    for(i=0;i<vi[u].size();i++)
    {
        v= vi[u][i];
        if(num[v]==-1)
        {
            chi++;
            par[v] = u;
            DFS(v);
            low[u] = min(low[u],low[v]);
            if( num[u] == 1)
            {
                if(chi>1)   isar[u]=true;
            }
            else if( low[v]>=num[u] )     isar[u] = true;
        }
        else if(v != par[u])
            low[u] = min(low[u],num[v]);
    }
}

int main()
{
    int i,j,u,v;
    istringstream iss;

    while(scanf("%d",&n)==1 && n)
    {
        memset(num,-1,sizeof(num));
        memset(isar,false,sizeof(isar));

        for(i=1;i<=n;i++)   vi[i].clear();
        gets(a);
        while(gets(a))
        {
            iss.clear();
            iss.str(a);
            iss>>u;
            if(!u)  break;
            while(iss>>v)
            {
                vi[u].push_back(v);
                vi[v].push_back(u);
            }
        }
        cnt=1;
        par[1]=-1;
        DFS(1);

        for(cnt=0,i=1;i<=n;i++)   if(isar[i]) cnt++;
        printf("%d\n",cnt);
    }

    return 0;
}


