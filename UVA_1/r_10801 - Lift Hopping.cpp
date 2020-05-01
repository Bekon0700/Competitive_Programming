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
#define ERR         1e-5
#define PI          3.141592653589793
#define pi          2*acos(0)
#define PB          push_back
#define INS         insert
#define ISS         istringstream
#define OSS         ostringstream
#define LL          long long
#define LD          long double
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<LL>
#define IR          iterator
#define SZ          size()
#define fi(i,a,b)   for(i=a;i<b;i++)
#define fd(i,a,b)   for(i=a;i>b;i--)
#define fii(a,b)   for(i=a;i<b;i++)
#define fdi(a,b)   for(i=a;i>b;i--)
#define fij(a,b)   for(j=a;j<b;j++)
#define fdj(a,b)   for(j=a;j>b;j--)
#define fik(a,b)   for(k=a;k<b;k++)
#define fdk(a,b)   for(k=a;k>b;k--)
#define fil(a,b)   for(l=a;l<b;l++)
#define fdl(a,b)   for(l=a;l>b;l--)
#define ri(i,a)    for(i=0;i<a;i++)
#define rd(i,a)    for(i=a;i>-1;i--)
#define rii(a)     for(i=0;i<a;i++)
#define rdi(a)     for(i=a;i>-1;i--)
#define rij(a)     for(j=0;j<a;j++)
#define rdj(a)     for(j=a;j>-1;j--)
#define rik(a)     for(k=0;k<a;k++)
#define rdk(a)     for(k=a;k>-1;k--)
#define ril(a)     for(l=0;l<a;l++)
#define rdl(a)     for(l=a;i>-1;l--)
#define sqr(a)     (a*a)
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))

struct pq{int n,t,l;bool operator <(const pq &b)const{return t>b.t;}};
int dis[100][6],k,n,lt[6];
VI ladj[6],adj[100];

int DIJKSTRA()
{
    int i,j,m,ch,l,f;
    pq u,v;
    priority_queue<pq>Q;

    u.n=0; u.t=0; u.l=1;    Q.push(u);

    while(!Q.empty())
    {
        u = Q.top();Q.pop();

        rii(adj[u.n].size())
        {
            l = adj[u.n][i];
            rij(ladj[l].size())
            {
                f = ladj[l][j];
                ch=60;
                if(!u.n || u.l == l)    ch=0;
                if(dis[f][l]>u.t+abs(u.n-f)*lt[l]+ch)
                {
                    v.t=dis[f][l]= u.t+abs(u.n-f)*lt[l]+ch;
                    v.n=f;v.l=l;
                    Q.push(v);
                }
            }
        }
    }
    m=oo;
    fii(1,n+1)
        m = min(m,dis[k][i]);
    return m;
}

int main()
{
    //freopen("in.in","r",stdin);
    int i,j,f,time;
    char a[1000];
    ISS iss;

    while(scanf("%d%d",&n,&k)==2)
    {

        fii(0,100)
        {
            fij(1,n+1)  dis[i][j] = oo;
            adj[i].clear();
        }
        fii(1,n+1)    dis[0][i] = 0;

        fii(1,n+1)    scanf("%d",&lt[i]);
        scanf("%c",&a[0]);
        fii(1,n+1)
        {
            gets(a);
            iss.clear();
            iss.str(a);
            ladj[i].clear();
            while(iss>>f)
            {
                ladj[i].PB(f);
                adj[f].PB(i);
            }
        }
        time= DIJKSTRA();
        if(time < oo)  printf("%d\n",time);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
