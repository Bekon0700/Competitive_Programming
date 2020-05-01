#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

#define sz 110

bool iar[sz];
int par[sz],cnt,n,low[sz],dn[sz];
vector<int>aj[sz];
vector<string>vs;

void DFS(int u)
{
    int i,chi=0,v;
    dn[u]=low[u] = cnt++;

    for(i=0;i<aj[u].size();i++)
    {
        v = aj[u][i];
        if(par[v]==-1)
        {
            chi++;
            par[v] = u;
            DFS(v);
            low[u] = min(low[u],low[v]);
            if(dn[u]==1)
            {
                if(chi>1)   iar[u]=true;
            }
            else if(low[v]>=dn[u])  iar[u] = true;

        }
        else if(v != par[u])
            low[u] = min(low[u],dn[v]);
    }
}

int main()
{
    int i,m,k,t=0,u,v;
    string su,sv,s;
    map<string,int>ms;
    map<int,string>mi;
    //freopen("in.in","r",stdin);

    while(scanf("%d",&n)==1 && n)
    {
        if(t++)   cout<<endl;
        ms.clear();mi.clear();vs.clear();

        for(i=1;i<=n;i++)
        {
            aj[i].clear();
            par[i] = -1;
            iar[i] = false;
        }
        for(i=k=0;i<n;i++)
        {
            cin>>s;
            ms[s] = ++k;
            mi[k] = s;
        }
        scanf("%d",&m);

        while(m--)
        {
            cin>>su>>sv;
            u = ms[su];
            v = ms[sv];
            aj[u].push_back(v);
            aj[v].push_back(u);
        }

        for(i=1;i<=n;i++)
            if(par[i]==-1)
            {
                cnt=1;
                par[i]=0;
                DFS(i);
            }

        for(i=1,cnt=0;i<=n;i++)
            if(iar[i])
            {
                vs.push_back(mi[i]);
                cnt++;
            }
        if(cnt)
            sort(vs.begin(),vs.end());
        printf("City map #%d: %d camera(s) found\n",t,cnt);
        for(i=0;i<vs.size();i++)
            cout<<vs[i]<<endl;

    }

    return 0;
}
