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
#define INC(a,b,c)   (b<=a&&a<=c)

template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
//typedef struct {int x,y;}P;

const LL M=1000000007;
LL mm[7][78200];
int n,m,ar[5],lst[9];
bool col[7][7];

LL dfs(int r,int msk,int cv,int c);
LL go(int u,int msk);


int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.in","w",stdout);
    //ios_base::sync_with_stdio(false);

    int tks,ks=1,i,u,v,k;

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d%d",&n,&m);
        n++;
        m++;
        mem(col,false);
        mem(mm,-1);
        //rii(m)  lst[i]=4;

        scanf("%d",&k);

        while(k--)
        {
            scanf("%d%d",&u,&v);
            u--;
            v--;
            col[u][v]=true;

        }

        u = go(0,0);

        printf("Case %d: %d\n",ks++,u);
    }




    return 0;
}
//Case 2: 548529085

LL dfs(int r,int msk,int cv,int c)
{
    if(c==m)    return go(r+1,cv);

    if(col[r][c])   return dfs(r,msk,cv*5,c+1);

    LL i,l,p,re=0;
    l=cv%5;
    p=msk/pow(5,m-c-1);
    p%=5;
    fii(1,5)
        if(p!=i && l!=i)
        {
            re+=dfs(r,msk,cv*5+i,c+1);
            re%=M;
        }
    //cout<<r<<" "<<c<<" "<<re<<" msk: "<<msk<<" l,p:"<<l<<p<<endl;
    return re;
}


LL go(int u,int msk)
{
    if(u==n)    return 1;

    int i,x,k=0,ok=msk;
    mem(ar,-1);

    for(i=0;i<m;i++)
    {
        if(ar[ok%5]==-1)    ar[ok%5]=k++;
        lst[i]=ar[ok%5];
        ok/=5;
    }
    ok=0;
    for(i=m-1;i>-1;i--) ok=ok*5+lst[i];

    LL &re=mm[u][ok];
    if(re>-1)   return re;
    re=0;
    return re=dfs(u,msk,0,0)%M;
}

