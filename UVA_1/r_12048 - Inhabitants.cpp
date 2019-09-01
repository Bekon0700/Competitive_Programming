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


//#include<cmath>
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

const double pi=2*acos(0.);

template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}

typedef struct {
    LL x,y;    double an;
    //void read(){    scanf("%I64d%I64d",&x,&y);}
    void read(){    scanf("%lld%lld",&x,&y);}
    void print(){printf("x:%I64d  y:%I64d  an:%lf\n",x,y,an);}

}P;

P p[100020];
set<P>s;

bool operator<(const P &a,const P &b){    return a.an<b.an;}

P MV(P a,P b){b.x-=a.x;b.y-=a.y;return b;}
LL CP(P a,P b){return a.x*b.y-a.y*b.x;}

P Pre(P a)
{
    if(s.count(a)>0)    return *s.find(a);
    set<P>IT i=s.lower_bound(a);
    if(i!=s.begin())    return *--i;
    return *--s.end();
}

P Nxt(P a)
{
    set<P> IT i=s.upper_bound(a);
    if(i!=s.end())    return *i;
    return *s.begin();
}


bool Isinside(P c){
    P a=Pre(c),b=Nxt(c);
    //a.print();
    //b.print();
//    cout<<"CP:"<<CP(MV(c,b),MV(c,a))<<endl;
    return (CP(MV(c,b),MV(c,a))<=0);
}

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.in","w",stdout);
    //ios_base::sync_with_stdio(false);

    int i,j,k,l,n,m,cnt,a,tks;
    P cp;
    double x,y;

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        s.clear();

        rii(n)
            p[i].read();

        p[0].an=0;
        x=y=0;
        rii(n)  x+=p[i].x,y+=p[i].y;

        x/=n;
        y/=n;

        rii(n)
        {
            p[i].an=atan2(p[i].y-y,p[i].x-x)+(atan2(p[i].y-y,p[i].x-x)<0?2*pi:0);
            s.insert(p[i]);
        }

        scanf("%d",&n);

        while(n--)
        {
            cp.read();
            cp.an=atan2(cp.y-y,cp.x-x);
            if(cp.an<0) cp.an+=2*pi;

            if(Isinside(cp)) puts("y");
            else puts("n");
        }

    }

    return 0;
}

