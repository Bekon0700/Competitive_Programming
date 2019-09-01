#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<math.h>

using namespace std;

#define pb(a) push_back(a);

typedef struct {int s,e;double v,a;}E;

struct pq{
    double d;
    int n;
    bool operator <(const pq &b)const{return d>b.d;}
};

double dis[1000],inf;
vector<int>adj[102];
vector<double>cst[102];
E edg[1000];
bool col[102];
int n,m;

double F_W(double v,double a,double t){
    double x;
    x = pow(a,t)/(v*log(a));
    return -log(x)/log(a);
}


double dijkstra(int c)
{
    priority_queue<pq>Q;
    pq u,v;
    int i;
    double rc,w;

    memset(dis,70,sizeof dis);
    memset(col,true,sizeof col);
    dis[1]=0;
    u.n = 1;
    u.d = 0;
    Q.push(u);

    while(!Q.empty())
    {
        u = Q.top();Q.pop();

        if(!col[u.n])   continue;
        col[u.n] = false;
        if(u.n==n)  return dis[u.n];

        for(i=0;i<(int)adj[u.n].size();i++)
        if(col[adj[u.n][i]])
        {
            if((adj[u.n][i]==edg[c].s && u.n==edg[c].e) ||
            (adj[u.n][i]==edg[c].e && u.n==edg[c].s))
            {
                w = F_W(edg[c].v,edg[c].a,dis[u.n]);
                if(w<0) rc = edg[c].v/pow(edg[c].a,dis[u.n]);
                else    rc = w+edg[c].v/pow(edg[c].a,w+dis[u.n]);
            }
            else rc=1e8;

            rc<?=cst[u.n][i];

            if(dis[u.n]+rc<dis[adj[u.n][i]])
            {
                v.n = adj[u.n][i];
                v.d = dis[v.n] = dis[u.n]+rc;
                Q.push(v);
            }
        }
    }
}

double solve()
{
    double re=1e8;

    for(int i=0;i<m;i++)
        re<?=dijkstra(i);
    return re;
}


int main()
{
    int i;

    while(scanf("%d%d",&n,&m)==2 && (n||m))
    {
        for(i=1;i<=n;i++){
            adj[i].clear();
            cst[i].clear();
        }

        for(i=0;i<m;i++)
        {
            scanf("%d%d%lf%lf",&edg[i].s,&edg[i].e,&edg[i].v,&edg[i].a);
            adj[edg[i].s].pb(edg[i].e);
            adj[edg[i].e].pb(edg[i].s);
            cst[edg[i].s].pb(edg[i].v);
            cst[edg[i].e].pb(edg[i].v);
        }

        printf("%.3lf\n",solve());
    }
    return 0;
}

