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

#define deb(a)      cout<<" -> "<<#a<<"  "<<a<<endl;
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          2*acos(0)
#define ERR         1e-3
#define PRE         1e-8
#define popcount(a) (__builtin_popcount(a))
#define SZ(a)       ((int)a.size())
#define PB          push_back
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
#define SS          stringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
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
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define p2(a)       (1LL<<a)

typedef struct {double x,y;}P;
typedef struct {P p[5];
    void scan()
    {
        scanf("%lf%lf%lf%lf",&p[0].x,&p[0].y,&p[2].x,&p[2].y);
        p[1].x=p[2].x;
        p[1].y=p[0].y;
        p[3].x=p[0].x;
        p[3].y=p[2].y;
        p[4]=p[0];
    }
}R;


double D;
P MV(P a,P b){b.x-=a.x;b.y-=a.y;return b;}
double CP(P a,P b){return a.x*b.y-a.y*b.x;}
double DP(P a,P b){return a.x*b.x+a.y*b.y;}
double ABS(P a){return sqrt(sqr(a.x)+sqr(a.y));}


double P2S(P a,P b,P c)
{
    double X,Y,T,a1,b1,c1;
    if(DP(MV(b,a),MV(b,c))<0)
    {
        if(fabs(fabs(a.x-b.x)-fabs(a.y-b.y))<D)
        {
            if(max(fabs(a.x-b.x),fabs(a.y-b.y))-D<=0)   return 0;
            X = fabs(a.x-b.x);
            Y = fabs(a.y-b.y);
            b1 = 2*(X+Y);
            c1 = sqr(X)+sqr(Y)-sqr(D);

            return (b1-sqrt(sqr(b1)-4*2*c1))/4;
        }
        else return max(fabs(a.x-b.x),fabs(a.y-b.y))-D;
    }
    if(DP(MV(c,a),MV(c,b))<0)
    {
        b=c;
        if(fabs(fabs(a.x-b.x)-fabs(a.y-b.y))<D)
        {
            if(max(fabs(a.x-b.x),fabs(a.y-b.y))-D<=0)   return 0;
            X = fabs(a.x-b.x);
            Y = fabs(a.y-b.y);
            b1 = 2*(X+Y);
            c1 = sqr(X)+sqr(Y)-sqr(D);

            return (b1-sqrt(sqr(b1)-4*2*c1))/4;
        }
        else return max(fabs(a.x-b.x),fabs(a.y-b.y))-D;
    }
    return (fabs(CP(MV(b,a),MV(b,c)))/ABS(MV(b,c)))-D;
}


double CalDis(R a,R b)
{
    int i,j;
    double mx=1e10;

    ///Whether intersects?

    rii(4)   if(a.p[0].x<=b.p[i].x && b.p[i].x<=a.p[2].x &&
                a.p[0].y<=b.p[i].y &&b.p[i].y<=a.p[2].y) return 0;

    rii(4)   if(b.p[0].x<=a.p[i].x && a.p[i].x<=b.p[2].x &&
                b.p[0].y<=a.p[i].y &&a.p[i].y<=b.p[2].y) return 0;

    ///Minimum distance
    rii(4)rij(4)    mx<?=P2S(a.p[i],b.p[j],b.p[j+1]);
    rii(4)rij(4)    mx<?=P2S(b.p[i],a.p[j],a.p[j+1]);
    return mx;
}


int main()
{
    //freopen("A.in","r",stdin);
    //freopen("ou.in","w",stdout);
    R rec[55];
    int i,j,k,ks=1,t,n;
    double r,mx;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        rii(n)  rec[i].scan();

        scanf("%lf%lf",&r,&D);

        mx=1e10;
        rii(n)  fij(i+1,n)  mx<?=CalDis(rec[i],rec[j]);

        mx>?=0;

        printf("Case %d: %.3lf\n",ks++,mx/(2*r));
    }

    return 0;
}

