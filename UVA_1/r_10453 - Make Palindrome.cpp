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
#define CON(a,b)  ((a).find(b)!=(a).end())
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
#define EX(msk,a)   (msk&p2(a))
#define INC(a,b,c)   (b<=a&&a<=c)

const double pi=2*acos(0.);
//const double pi=acos(-1.0);

template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
template<class ZZ>ZZ max(ZZ a,ZZ b,ZZ c){return max(a,max(b,c));}
template<class ZZ>ZZ min(ZZ a,ZZ b,ZZ c){return min(a,min(b,c));}

//typedef pair< , > pi;
//typedef struct {int x,y;void print(){printf("%d %d\n",x,y);}}P;
//bool operator < (const P &a,const P &b){return a>b;}
//bool com(P a,P b){return;}
//struct pq{int n,w;  bool operator<(const pq &b)const{return w>b.w;}};

int mm[1001][1001];
int op[1001][1001];
char a[1001];

int go(int l,int h)
{
    if(l>=h) return 0;
    int &re=mm[l][h];
    int &o=op[l][h];
    if(re>-1)   return re;

    o=-1;
    re=2000;

    if(a[l]==a[h] && re>go(l+1,h-1))
    {
        re=go(l+1,h-1);
        o=1;
    }
    else
    {
        if(re>go(l+1,h)+1)
        {
            re=go(l+1,h)+1;
            o=2;
        }
        if(re>go(l,h-1)+1)
        {
            re=go(l,h-1)+1;
            o=3;
        }
    }

    return re;
}


void pp(int l,int h)
{
    if(l==h)    printf("%c",a[l]);
    if(l>h)     return ;

    if(op[l][h]==1)
    {
        printf("%c",a[l]);
        pp(l+1,h-1);
        printf("%c",a[h]);
    }
    else if(op[l][h]==2)
    {
        printf("%c",a[l]);
        pp(l+1,h);
        printf("%c",a[l]);

    }
    else if(op[l][h]==3)
    {
        printf("%c",a[h]);
        pp(l,h-1);
        printf("%c",a[h]);
    }

}

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.out","w",stdout);
    //ios_base::sync_with_stdio(false);

    int i,j,k,tks,ks=1,n,m,l;


    while(scanf("%s",a)==1)
    {
        mem(mm,-1);
        l = strlen(a);
        printf("%d ",go(0,l-1));
        pp(0,l-1);
        printf("\n");
    }

    return 0;
}


