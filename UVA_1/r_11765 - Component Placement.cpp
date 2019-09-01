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
#include<string.h>
#include<iostream>
#include<stdio.h>
using namespace std;

#define oo          1000000000
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
#define MEM(a,b)      memset(a,b,sizeof(a))
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


//struct pq{int n,c;bool operator <(const pq &b)const{return c>b.c;}};
int mat[204][204],par[204],cf;
VI lst[202];

void MR(int u)
{
    cf = min(cf,mat[par[u]][u]);
    if(par[u])   MR(par[u]);
    mat[par[u]][u] -= cf;
    mat[u][par[u]] += cf;
}

bool BFS(int sink)
{
    int i,u,v;

    queue<int>Q;
    MEM(par,-1);
    Q.push(0);
    par[0] = -2;

    while(!Q.empty())
    {
        u=Q.front();Q.pop();

        rii(lst[u].size())
        {
            v = lst[u][i];
            if(mat[u][v]>0 && par[v]==-1)
            {
                par[v] = u;
                if(v==sink) return true;
                Q.push(v);
            }
        }
    }
    return false;
}


LL MaxFlow(int n)
{
    LL flow=0;

    while( BFS(n) )
    {
        cf=oo;
        MR(n);
        flow+=cf;
    }
    return flow;
}

int main()
{
    //freopen("in.in","r",stdin);
    int t,i,j,n,m,u,v,c;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);
        MEM(mat,0);
        rii(n+2)    lst[i].clear();
        rii(n)  scanf("%d",&mat[0][i+1]);
        rii(n)  scanf("%d",&mat[i+1][n+1]);
        fii(1,n+1)
        {
            lst[i].PB(n+1);
            lst[0].PB(i);
        }
        rii(n)
        {
            scanf("%d",&u);
            if(u==1)    mat[i+1][n+1]=oo;
            if(u==-1)    mat[0][i+1]=oo;
        }
        rii(m)
        {
            scanf("%d%d%d",&u,&v,&c);
            mat[v][u]=mat[u][v]=c;
            lst[u].PB(v);
            lst[v].PB(u);
        }

        printf("%lld\n",MaxFlow(n+1));
    }

    return 0;
}

