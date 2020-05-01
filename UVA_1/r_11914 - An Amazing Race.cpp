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
#include<list>
#include<utility>
#include<functional>
#include <deque>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <ctime>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;

#define SZ(a)       ((int)a.size())
#define PB          push_back
#define mem(a,b)    memset(a,b,sizeof(a))
#define memc(a,b)   memcpy(a,b,sizeof(b))
#define rii(a)      for(i=0;i<a;i++)
#define rdi(a)      for(i=a;i>-1;i--)
#define rij(a)      for(j=0;j<a;j++)
#define p2(a)       (1LL<<a)

string sm[15][15],ps="ENSW";
int dis[25][25],par[25][25],x[15],y[15],dm[20][20];
int n,ne,m;
int dx[]={0,-1,1,0};
int dy[]={1,0,0,-1};
char lnd[25][25];
int rnk[500],Par[500];

int D[15][10000];
string M[15][5000];


typedef struct {int u,v,d;string s;}E;
E e[500];

bool com(E a,E b){
    if(a.s!=b.s)return a.d<b.d;
    return a.s<b.s;
}


void BFS(int s,int r,int c)
{
    int i,ux,uy,vx,vy;
    queue<int>q;
    mem(dis,1);
    mem(par,-1);

    dis[x[s]][y[s]]=0;
    par[x[s]][y[s]]=4;
    q.push(x[s]);
    q.push(y[s]);

    while(!q.empty())
    {
        ux=q.front();q.pop();
        uy=q.front();q.pop();

        rii(4)
        {
            vx=ux+dx[i];
            vy=uy+dy[i];
            if(vx>-1 &&vy>-1 && vx<r && vy<c &&(lnd[vx][vy]=='#' || isalpha(lnd[vx][vy]))
            && dis[ux][uy]+1<dis[vx][vy])
            {
                par[vx][vy] = i;
                dis[vx][vy] = 1+dis[ux][uy];
                q.push(vx);
                q.push(vy);
            }
        }
    }
}

void PP(int ux,int uy,int vx,int vy,int s,int d)
{
    if(ux==vx && uy==vy) return;
    int k=par[vx][vy];
    PP(ux,uy,vx-dx[k],vy-dy[k],s,d);
    sm[s][d]+=ps[k];
}


void CAL_DIS(int r,int c)
{
    int i,j;

    n=2;

    rii(r)rij(c)
        if(isalpha(lnd[i][j]))
        {
            if(lnd[i][j]=='S')  x[0]=i,y[0]=j;
            else if(lnd[i][j]=='T')  x[1]=i,y[1]=j;
            else
            {

                x[n]=i;
                y[n++]=j;
            }

        }


    ne=0;
    rii(n)
    {
        BFS(i,r,c);

        rij(n)    if(i!=j)
        {
            dm[i][j]=dis[x[j]][y[j]];
            sm[i][j]="";
            PP(x[i],y[i],x[j],y[j],i,j);

            e[ne].u=i;e[ne].v=j;e[ne].s=sm[i][j];e[ne].d=SZ(sm[i][j]);ne++;

        }
    }

}

void ini(int nm)
{
    int i;
    for(i=0;i<nm;i++)
    {
        rnk[i]=0,Par[i]=i;
    }
}

int FS(int u)
{
    if(Par[u]!=u)
        Par[u]=FS(Par[u]);

    return Par[u];
}

void L(int u,int v)
{
    if(rnk[u]>rnk[v])   Par[v]=u;
    else Par[u]=v;
    if(rnk[v]==rnk[u])  rnk[v]++;
}

void Kruskal()
{
    ini(n);

    m=0 ;
    int i;
    sort(e,e+ne,com);

    rii(ne)
        if(FS(e[i].u)!=FS(e[i].v))
        {
            m = max(m,e[i].d);
            L(FS(e[i].u),FS(e[i].v));
        }
}


struct pq
{
    int vn,msk,d;
    string cst;

    bool operator<(const pq &b)const
    {
        if(d!=b.d)   return d>b.d;
        return cst>b.cst;
    };
};



void Dijkstra(int k)
{
    string s;
    int oo=300000,i,msk,cos,j;
    pq u,v;
    priority_queue<pq>Q;



    for(i=0;i<=n;i++)
    {
        for(j=0;j<(1<<n);j++) D[i][j]=oo,M[i][j].clear();
    }

    u.d=D[0][p2(0)]=0;
    u.vn = 0;
    u.msk = p2(0);
    u.cst=M[0][p2(0)]="";

    Q.push(u);

    while(!Q.empty())
    {
        u = Q.top();
        Q.pop();

        if(__builtin_popcount(u.msk)==k+2 && u.vn==1 )
        {
            cout<<u.cst<<endl;
            return ;
        }


        for(i=0;i<n;i++) //if((u.msk&p2(i)) == 0)
        {
            if(SZ(sm[u.vn][i])>m)  continue;

            s = M[u.vn][u.msk]+sm[u.vn][i];
            cos = D[u.vn][u.msk]+SZ(sm[u.vn][i]);
            msk = (u.msk|p2(i));
            if(D[i][msk]>cos)
            {
                v.d=D[i][msk]=cos;
                v.msk = msk;
                v.vn=i;
                v.cst= M[i][msk] = s;
                Q.push(v);
            }
            else if(D[i][msk]== cos && M[i][msk]>s)
            {
                v.d=D[i][msk]=cos;
                v.msk = msk;
                v.vn=i;
                v.cst= M[i][msk] = s;
                Q.push(v);
            }
        }
    }
}

int main()
{
    //freopen("D.in","r",stdin);
    //freopen("ou.in","w",stdout);
    int i,K,r,c;


    while(scanf("%d%d%d",&r,&c,&K)==3)
    {
        rii(r)  scanf("%s",lnd[i]);
        CAL_DIS(r,c);

        Kruskal();
        Dijkstra(K);
    }

    return 0;
}








