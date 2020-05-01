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

#define oo        (1<<30)
#define PI          3.141592653589793
#define pi          2*acos(0)
#define PB          push_back
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define ISS         istringstream
#define OSS         ostringstream
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

template<class T>T sqr(T a) {return a*a;}
typedef long long LL;typedef vector<string>VS;typedef vector<int>VI;typedef vector<double>VD;typedef vector<long long>VLL;
typedef struct{int u,v,c;}E;
E e[100000];
int rank[10001],par[10001];

bool comp(E a,E b)  {return a.c<b.c;}
void Make_Set(int nv){  int i;rii(nv+1)par[i]=i,rank[i]=0;  }
int Find_Set(int u){    if(par[u]!=u)  par[u] = Find_Set(par[u]); return par[u];}
void Union(int u,int v){
    if(rank[u]>rank[v]) par[v] = u;
    else {
            par[u] = v;
            if(rank[u]==rank[v])    rank[v]++;

        }
    }

int Kruskel(int nv,int ne,int A)
{
    int i,x,y,cost=0;

    sort(&e[0],&e[ne],comp);
    rii(ne)
        if(e[i].c<A)    {
            x= Find_Set(e[i].u);
            y= Find_Set(e[i].v);
            if(x!=y){
                cost+=e[i].c;
                Union(x,y);
            }
        }
        else break;

    return cost;
}


int main(){
    int i,t=1,T,cost,cou,nv,ne,A;
    //freopen("in.in","r",stdin);

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&nv,&ne,&A);
        Make_Set(nv);
        rii(ne) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
        cost = Kruskel(nv,ne,A);
        cou=0;
        fii(1,nv+1) if(par[i]==i)   cou++;
        cost+=cou*A;

        printf("Case #%d: %d %d\n",t++,cost,cou);
    }

    return 0;
}

