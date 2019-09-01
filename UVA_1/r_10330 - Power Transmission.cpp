#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>

using namespace std;
#define INF         9999999999999999LL
#define oo          (1<<29)
#define PI          3.141592653589793
#define pi          2*acos(0)
#define ERR         1e-5
#define PRE         1e-8
#define SZ          size()
#define PB          push_back
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define fi(i,a,b)   for(i=a;i<b;i++)
#define fd(i,a,b)   for(i=a;i>b;i--)
#define fii(a,b)    for(i=a;i<b;i++)
#define fdi(a,b)    for(i=a;i>b;i--)
#define fij(a,b)    for(j=a;j<b;j++)
#define fdj(a,b)    for(j=a;j>b;j--)
#define fik(a,b)    for(k=a;k<b;k++)
#define fdk(a,b)    for(k=a;k>b;k--)
#define fil(a,b)    for(l=a;l<b;l++)
#define fdl(a,b)    for(l=a;l>b;l--)
#define ri(i,a)     for(i=0;i<a;i++)
#define rd(i,a)     for(i=a;i>-1;i--)
#define rii(a)      for(i=0;i<a;i++)
#define rdi(a)      for(i=a;i>-1;i--)
#define rij(a)      for(j=0;j<a;j++)
#define rdj(a)      for(j=a;j>-1;j--)
#define rik(a)      for(k=0;k<a;k++)
#define rdk(a)      for(k=a;k>-1;k--)
#define ril(a)      for(l=0;l<a;l++)
#define rdl(a)      for(l=a;i>-1;l--)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define PP(a)       (cout<<a<<endl)
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))

#define VSZ 210
typedef struct{}P;
LL mat[VSZ][VSZ],flow;
int par[VSZ],n,m;
VI adj[VSZ];

bool BFS(int so,int si)
{
    int u,v,i;
    queue<int>Q;

    memset(par,-1,sizeof(par));

    Q.push(so);
    par[so] = -2 ;

    while(!Q.empty())
    {
        u = Q.front();    Q.pop();

        rii(adj[u].SZ)
        {
            v = adj[u][i];
            if(par[v]==-1 && mat[u][v]>0)
            {
                par[v] = u;
                if(v == si)    return true;
                Q.push(v);
            }
        }
    }
    return false;
}

void MR(int t)
{
    flow = min(mat[par[t]][t],flow);
    if(par[t])  MR(par[t]);
    mat[par[t]][t] -= flow;
    mat[t][par[t]] += flow;
}

LL MF(int so,int si)
{
    LL ret=0;

    while(BFS(so,si))
    {
        flow = INF;
        MR(si);
        ret+=flow;

    }
    return ret;
}

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    LL  u,v,f,i,j,k,B,D,so,si;

    while(scanf("%lld",&n)==1)
    {

        memset(mat,0,sizeof(mat));
        si = n+1;
        so = 0;

        fii(1,si)
        {
            scanf("%lld",&mat[i][si+i]);
            adj[i].PB(si+i);
            adj[si+i].PB(i);
        }
        scanf("%lld",&m);

        while(m--)
        {
            scanf("%lld%lld%lld",&u,&v,&f);
            mat[u+si][v] = f;
            adj[u+si].PB(v);
            adj[v].PB(u+si);
        }

        scanf("%lld%lld",&B,&D);
        rii(B)
        {
            scanf("%lld",&u);
            mat[so][u] = INF;
            adj[so].PB(u);
            adj[u].PB(so);
        }

        rii(D)
        {
            scanf("%lld",&u);
            mat[u+si][si] = INF ;
            adj[u+si].PB(si);
            adj[si].PB(u+si);
        }

        printf("%lld\n",MF(so,si));
    }

    return 0;
}






