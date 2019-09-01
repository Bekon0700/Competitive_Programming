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


#define oo          (1<<30)
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
#define sz 103
struct pq{int n,d;bool operator <(const pq &b)const {return d>b.d;}};

bool col[sz],ex[sz];
int db[sz],dp[sz],pb[sz],pp[sz];
VI adj[sz],cost[sz];

void DJB(int s)
{
    int i;
    priority_queue<pq>q;
    pq u,v;

    u.n = s;
    u.d=db[s]=0;
    q.push(u);
    while(!q.empty())
    {
        u = q.top();q.pop();
        if(!col[u.n])continue;
        col[u.n] = false;
        rii(adj[u.n].SZ)
            if(col[adj[u.n][i]] && db[adj[u.n][i]]>u.d+cost[u.n][i])
            {
                v.n = adj[u.n][i];
                v.d = db[v.n]= u.d+cost[u.n][i];
                pb[v.n] = u.n;
                q.push(v);
            }
    }
}

void DJP(int s)
{
    int i;
    priority_queue<pq>q;
    pq u,v;

    u.n = s;
    u.d=dp[s]=0;
    q.push(u);

    while(!q.empty())
    {
        u = q.top();q.pop();
        if(!col[u.n])continue;
        col[u.n] = false;
        rii(adj[u.n].SZ)
            if(col[adj[u.n][i]] && dp[adj[u.n][i]]>u.d+cost[u.n][i])
            {
                v.n = adj[u.n][i];
                v.d = dp[v.n]= u.d+cost[u.n][i];
                pp[v.n] = u.n;
                q.push(v);
            }
    }
}

double SP(int a,int b)
{
    return ( (double)a / ( (double)b / 160.0)) ;
}

int main(){
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int i,u,v,l,b,p,nv,ne,nh,t,x,y,z;
    double m;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d%d",&nv,&ne,&nh);

        rii(nv+1)
        {
            db[i]=dp[i]= oo;
            adj[i].clear();
            cost[i].clear();
        }

        memset(ex,false,sizeof(bool)*(nv+3));
        rii(ne){
            scanf("%d%d%d",&u,&v,&l);
            adj[u].PB(v);cost[u].PB(l);
            adj[v].PB(u);cost[v].PB(l);
            }

        rii(nh)
        {
            scanf("%d",&u);
            ex[u] = true;
        }
        scanf("%d%d",&b,&p);

        memset(col,true,sizeof(bool)*(nv+3));

        col[p] = false;
        DJB(b);

        memset(col,true,sizeof(bool)*(nv+3));
        DJP(p);

        m = oo;

        fii(1,nv+1)
            if(ex[i] && db[i]<oo)
                if(dp[i]<=oo)
                {
                    if(dp[i]>=db[i])    m = min(m,SP(db[i],dp[i]));
                    else
                    {
                        x=y=z=i;
                        while(pb[x]==pp[y])
                        {
                            z = pb[x];
                            x = pb[x];
                            y = pp[y];
                        }
                        m = min(m,SP(db[z],dp[z]));
                    }
                }
                else m=0.0;
        if(EQ(m,oo))    printf("IMPOSSIBLE\n");
        else printf("%.10lf\n",m);

    }
    return 0;
}

