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
#include <assert.h>


#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

#define deb(a)      cerr<<" -> "<<#a<<"  "<<a<<endl;
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
#define SS          stringstream
#define VS          vector<string>
#define VI          vector<int>
#define CON(a,b)  ((a).find(b)!=(a).end())
#define mem(a,b)    memset(a,b,sizeof(a))
#define memc(a,b)   memcpy(a,b,sizeof(b))
#define accu(a,b,c) accumulate((a),(b),(c))
#define fi(i,a,b)   for(i=a;i<b;i++)
#define fii(a,b)    for(i=a;i<b;i++)
#define fij(a,b)    for(j=a;j<b;j++)
#define fik(a,b)    for(k=a;k<b;k++)
#define fil(a,b)    for(l=a;l<b;l++)
#define ri(i,a)     for(i=0;i<a;i++)
#define rii(a)      for(i=0;i<a;i++)
#define rij(a)      for(j=0;j<a;j++)
#define rik(a)      for(k=0;k<a;k++)
#define ril(a)      for(l=0;l<a;l++)
#define fore(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define rall(a)      (a).rbegin(),(a).rend()
//#define sqr(a)      ((a)*(a))
#define p2(a)       (1LL<<a)
#define EX(msk,a)   (msk&p2(a))
#define INC(a,b,c)   (b<=a&&a<=c)


//#define debug(args...)          {dbg,args; cerr<<endl;}
//#define debug(args...)          {cout<<" #--> ";dbg,args; cerr<<endl;}
#define debug(a...)          {cerr<<" #--> ";dbg,a; cerr<<endl;}

struct debugger
{
    ///Collected from rudradevbasak
    template<typename T> debugger& operator , (const T v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;




//const double pi=2*acos(0.);
const double pi=acos(-1.0);

const double eps=1e-7;

template<class TT>TT sqr(TT a){return a*a;}

template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
template<class ZZ>ZZ max(ZZ a,ZZ b,ZZ c){return max(a,max(b,c));}
template<class ZZ>ZZ min(ZZ a,ZZ b,ZZ c){return min(a,min(b,c));}

//typedef pair<int,int> pii;

//typedef double type;
//struct P{
//    type x,y,z;
//    P(type xi=0,type yi=0,type zi=0):x(xi),y(yi),z(zi){};
//    void scan(){cin>>x>>y>>z;}
//    void scan1(){scanf("%lf%lf%lf",&x,&y,&z);}
//};


//bool operator < (const P &a,const P &b){return a>b;}
//bool com(P a,P b){return;}

//struct pq{int n,w;
//    pq(int nn=0,int ww=0):n(nn),w(ww){}
//    bool operator<(const pq &b) const{return w<b.w;}
//};

double a[15];
int n;

//double Cal(double x)
//{
//    double up=0,low=0;
//    int i;
//    for(i=0;i<=n;i++)
//    {
//        up+=a[i]*pow(x,i);
//        if(i)   low+=i*a[i]*pow(x,i-1);
//    }
//    return pow(up,3)/(low*3.0);
//}
//
//
//double Volume(double xh,double xl)
//{
//    if(n==0)    return pi*pow(a[0],2.0)*(xh-xl);
//    return pi*(Cal(xh)-Cal(xl));
//}

double Volume(double xh,double xl)
{
    double ret=0;
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            ret+=a[i]*a[j]*(pow(xh,i+j+1)-pow(xl,i+j+1))/(i+j+1);
    return pi*ret;
}

double Find(double xl,double xh,double vol)
{
    int i=70;
    double l=xl,h=xh,m,cv;
    while(i--)
    {
        m = (l+h)/2.0;
        cv=Volume(m,xl);
        if(cv>vol)  h=m;
        else l=m;
    }
    return m;
}

int main()
{
    //freopen("bottle-005.in","r",stdin);
    //freopen("out.in","w",stdout);
    //ios_base::sync_with_stdio(false);
    //std::cout << std::setprecision(13)<<b<<std::endl;
    //assert(ks<0);

    int i,j,k,tks,ks=1,ivl;
    double xl,xh,vol,mrk;

//    scanf("%d",&tks);
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<=n;i++)   scanf("%lf",a+i);
        scanf("%lf%lf%d",&xl,&xh,&ivl);
        vol=Volume(xh,xl);

        printf("Case %d: %.2lf\n",ks++,vol);
        j=0;
        for(i=1;i<=8;i++)
            if(i*ivl<vol)
            {
                mrk=Find(xl,xh,(double)i*ivl);

                if(j++)   printf(" ");
                printf("%.2lf",mrk-xl);
            }
            else break;
        if(j)   printf("\n");
        else    printf("insufficient volume\n");

    }

    return 0;
}


