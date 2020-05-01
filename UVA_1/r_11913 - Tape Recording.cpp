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
#define ERR         1e-5
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

int n;
int mm[102][102][102];

typedef struct {int s,e,v;}M;
M mo[120];

bool com(M a,M b){return a.s<b.s;}

int go(int itm,int av1,int av2)
{
    if(itm==n)  return 0;
    int &re=mm[itm][av1][av2];
    if(re>-1)   return re;

    re=0;

    if(mo[av1].e<=mo[itm].s)
        re>?= go(itm+1,itm,av2) + mo[itm].v;
    if(mo[av2].e<=mo[itm].s)
        re>?= go(itm+1,av1,itm) + mo[itm].v;
    re>?=go(itm+1,av1,av2);

    return re;
}


int main()
{
    //freopen("in1.in","r",stdin);
    //freopen("ou.in","w",stdout);
    char x[100];
    int i,m,sh,sm,eh,em,ks=1,p;


    while(scanf("%d",&n)==1&&n)
    {
//        mp.clear();
//        p=0;
        rii(n)
        {
            scanf("%d:%d-%d:%d %d %[^\n]",&sh,&sm,&eh,&em,&mo[i].v,x);


            mo[i].s=60*sh+sm-360;
            mo[i].e=60*eh+em-360;
            if(mo[i].s<0)   mo[i].s+=1440;
            if(mo[i].e<0)   mo[i].e+=1440;


//            if(mp.find(mo[i].s)==mp.end())    mp[mo[i].s]=p++;
//            if(mp.find(mo[i].e)==mp.end())    mp[mo[i].e]=p++;

        }

        sort(mo,mo+n,com);

        mo[n].e=mo[n].s=mo[n].v=0;

        mem(mm,-1);
        m = go(0,n,n);

        printf("Case %d: %d\n",ks++,m);
    }

    return 0;
}

