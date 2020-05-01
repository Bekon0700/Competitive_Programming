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
#define ERR         1e-6
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
typedef struct{double x,y;}P;

P h[100],g[100];
bool col[100];
VI l[100];
int ng,nh,p[100];

void INPUT(double d){
    int i,j;
    rii(ng)  scanf("%lf%lf",&g[i].x,&g[i].y);
    rii(nh)  scanf("%lf%lf",&h[i].x,&h[i].y);

    rii(nh) l[i].clear();
    rii(nh)rij(ng)
        if(sqrt(sqr(h[i].x-g[j].x) +sqr(h[i].y-g[j].y) )<d || fabs(sqrt(sqr(h[i].x-g[j].x) +sqr(h[i].y-g[j].y)) - d )<ERR ){
            l[i].PB(j);
        }
    }

bool DFS(int u)
{
    int i,j;

    rii(l[u].size())
    if(col[l[u][i]])
    {
        col[l[u][i]] = false;

        if(p[ l[u][i] ]<0 || DFS(p[l[u][i]])){

            p[l[u][i]] = u;
            return true;
        }

    }

    return false;
}

int main()
{
    int i,c;
    double d,s;
    //freopen("in.in","r",stdin);

    while(scanf("%d%d%lf%lf",&ng,&nh,&s,&d)==4)
    {
        INPUT(d*s);
        c= 0;
        memset(p,-1,sizeof(p));
        rii(nh){memset(col,true,sizeof(col));if(DFS(i))   c++;}
        printf("%d\n",ng-c);
    }
    return 0;
}

