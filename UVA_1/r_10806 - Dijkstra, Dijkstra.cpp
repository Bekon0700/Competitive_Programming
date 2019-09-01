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


#define oo          (1<<28)
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
#define VSZ     102
struct pq { int n,c; bool operator >(const pq &b)const{ return c>b.c;}};
int mat[VSZ][VSZ],dis[VSZ],n,par[VSZ];
bool col[VSZ];
VI adj[VSZ];


void PATH(int s)
{
    mat[s][par[s]] =  -mat[par[s]][s];
    mat[par[s]][s] = oo;

    if(s != 1 ) PATH(par[s]);
}


void DIJ()
{
    int i,j,x,y;
    pq u,v;
    priority_queue<pq>q;
    rii(n+1)    {
        col[i] = true;
        dis[i]=oo;
    }
    u.n = 1 ;
    u.c=0;
    par[1]=1;
    dis[1]=0;
    q.push(u);

    while(!q.empty())
    {
        u = q.top();q.pop();
        if(u.n==n)  return ;
        if(col[u.n])
        {
            col[u.n] = false;
            rii(adj[u.n].size())
                if( col[adj[u.n][i]] && mat[u.n][adj[u.n][i]]<oo && dis[adj[u.n][i]]>mat[u.n][adj[u.n][i]]+u.c)
                {
                    v.c=dis[adj[u.n][i]] = mat[u.n][adj[u.n][i]]+u.c;
                    v.n=adj[u.n][i];
                    par[v.n] = u.n;
                    q.push(v);
                }
        }
    }
}


int main(){
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int i,j,m,cost,u,v,c,k;

    while(scanf("%d",&n)==1 && n)
    {
        scanf("%d",&m);
        fii(1,n+1)
        {
            fij(1,n+1)    mat[i][j] = oo;
            adj[i].clear();
        }
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&c);
            mat[u][v] = c;
            mat[v][u] = c;
            adj[u].PB(v);
            adj[v].PB(u);
        }
        DIJ();
        cost = dis[n];

        PATH(n);

        fik(1,n+1)fii(1,n+1)fij(1,n+1)
            if(mat[i][j] > mat[i][k] + mat[k][j] && mat[i][k] + mat[k][j]<oo)
                mat[i][j] = mat[i][k] + mat[k][j] ;

        cost += mat[1][n];
        if(cost<oo) printf("%d\n",cost);
        else printf("Back to jail\n");

    }
    return 0;
}

/*

CRITICAL INPUT:
***************
2
1
1 2 999
3
3
1 3 10
2 1 20
3 2 50
9
12
1 2 10
1 3 10
1 4 10
2 5 10
3 5 10
4 5 10
5 7 10
6 7 10
7 8 10
6 9 10
7 9 10
8 9 10
5
4
1 4 47
4 2 13
3 2 15
5 3 4
8
12
1 2 745
1 7 998
2 8 177
1 3 129
1 4 157
5 8 124
1 5 487
1 6 999
3 8 478
4 8 145
6 8 854
7 8 768
4
4
4 2 65
1 2 25
3 4 74
1 3 58
10
13
1 7 158
2 7 999
3 10 998
4 5 997
5 9 996
5 3 995
1 8 994
9 10 993
5 2 992
1 6 999
2 6 999
2 8 999
4 10 998
5
10
4 3 895
3 5 485
4 5 217
5 1 785
3 2 147
5 2 856
4 2 175
1 2 578
1 3 745
4 1 145
6
8
1 2 1
2 3 1
3 6 1
1 4 100
4 5 100
5 6 100
1 3 10
2 6 10
0

OUT PUT:
********
Back to jail
80
Back to jail
Back to jail
909
222
Back to jail
1147
22


*/
