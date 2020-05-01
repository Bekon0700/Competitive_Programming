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
#define sqr(a)      ((a)*(a))
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define VSZ     202

struct pq { int n;double c; bool operator <(const pq &b)const{ return c>b.c;}};
double mat[VSZ][VSZ],dis[VSZ],fdis[VSZ];
typedef struct {int x,y;}P;
P p[VSZ];
bool col[VSZ];
int n,par[VSZ];

double DIJ()
{
    int i,j,x,y;
    double m=0.0;
    pq u,v;
    priority_queue<pq>q;

    rii(n)    {
        col[i] = true;
        dis[i] = oo;
    }
    u.n = 0 ;
    u.c = 0;
    dis[0] = 0;
    par[0]=-1;

    q.push(u);

    while(!q.empty())
    {
        u = q.top();q.pop();
        m = max(m,dis[u.n]);
        if(u.n==1)  return m;
        if(!col[u.n])   continue;
        col[u.n] = false;

        rii(n)
            if( col[i] && mat[u.n][i] < dis[i])
            {
                v.c = dis[i] = mat[u.n][i];
                v.n=i;
                par[i] = u.n;
                q.push(v);
            }
    }
}

int main(){
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int i,j,cost,u,v,c,k,ks=1;

    while(scanf("%d",&n)==1 && n)
    {
        rii(n)  scanf("%d%d",&p[i].x,&p[i].y);

        rii(n) mat[i][i]=0.0;
        rii(n)fij(i+1,n)
            mat[i][j] = mat[j][i] = sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));

        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",ks++,DIJ());
    }
    return 0;
}





