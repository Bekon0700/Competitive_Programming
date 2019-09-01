#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<utility>
#include<functional>
#include <deque>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <ctime>


#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

#define deb(a)      cout<<" -> "<<#a<<"  "<<a<<endl;
#define oo          (1<<30)
#define ERR         1e-5
#define PRE         1e-8
#define popcount(a) (__builtin_popcount(a))
#define SZ(a)       ((int)a.size())
#define X           first
#define Y           second
#define PB          push_back
#define LL          long long
#define MP          make_pair
#define ISS         istringstream
#define OSS         ostringstream
#define SS          stringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define IT          ::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define memc(a,b)   memcpy(a,b,sizeof(b))
#define accu(a,b,c) accumulate((a),(b),(c))
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

#define fore(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)

#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define p2(a)       (1LL<<a)
#define INC(a,b,c)   (b<=a&&a<=c)

//const double pi=2*acos(0.);

template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
template<class ZZ>ZZ max(ZZ a,ZZ b,ZZ c){return max(a,max(b,c));}
template<class ZZ>ZZ min(ZZ a,ZZ b,ZZ c){return min(a,min(b,c));}

//typedef pair< , > pi;
typedef struct {LL u,v,w,c;
}P;



//bool operator < (const P &a,const P &b){    return (a.x!=b.x?a.x<b.x:a.y<b.y);}
//bool com(P a,P b){return(a.x!=b.x?a.x<b.x:a.y<b.y);}
struct pq{LL n,w;
pq(LL nn=0,LL ww=0 ){n=nn;w=ww;}
bool operator<(const pq &b)const{return w<b.w;}
};

const int R=205;
int m;
LL dis[R],par[R],S,T,E,flow,cap[205][205],cst[205][205];
vector<int>g[205];


void AddEdge(int u,int v,int w,int c)
{
    /**
        w = Weight
        c = Capacity
    */
    cap[u][v]=c;
    cap[v][u]=0;
    cst[u][v]=w;
    cst[v][u]=-w;
    g[u].push_back(v);
    g[v].push_back(u);
}




bool FindPath()
{
    priority_queue<pq>q;
    pq u,v;
    LL  i,j,co,no;

    for(i=0;i<=T;i++)   dis[i]=-oo,par[i]=-1;
    dis[S]=0;

    v.n=S;
    v.w=0;
    q.push(pq(S,0));

    while(!q.empty())
    {
        u = q.top();q.pop();

        for(i=0;i<SZ(g[u.n]);i++)
        {
            no=g[u.n][i];
            if(cap[u.n][no]>0 && dis[no]<u.w+cst[u.n][no])
            {
                dis[no]=u.w+cst[u.n][no];
                par[no]=u.n;
                q.push(pq(no,dis[no]));
            }
        }
    }
    return dis[T]>0;
}

void MR(int u)
{

    flow=min(flow,cap[par[u]][u]);
    if(par[u]!=S)   MR(par[u]);
    cap[par[u]][u]-=flow;
    cap[u][par[u]]+=flow;
}


LL MinCostMaxFlow()
{
    LL re=0;

    ///Because We need only four route.
    while(FindPath())
    {
        flow=oo;
        MR(T);

        re+=flow*dis[T];
    }
    return re;
}


int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.in","w",stdout);
    //ios_base::sync_with_stdio(false);

    int tks,ks=1,i,j,t;
    int mi, ni, pi, si, mt;
    LL re;

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d%d",&m,&t);
        S=0;
        T=2*m+1;
        E=0;

        for(i=0;i<=T;i++)   g[i].clear();

        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d%d%d",&mi,&ni,&pi,&si,&mt);

            AddEdge(S,i,-mi,ni);
            AddEdge(m+i,T,pi,si);
            for(j=0;j<=mt && i+j<=m;j++)
                AddEdge(i,m+i+j,-t*(j),oo);

        }

        re=MinCostMaxFlow();

        printf("Case %d: %lld\n",ks++,re);
    }
    return 0;
}


