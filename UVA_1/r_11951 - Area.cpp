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


long long dp[102][102];

int main()
{

    int ks=1,tks;

    long n,m,mv,mr,cr,cv,K;

    int i,j,k,l;
    scanf("%d",&tks);


    while(tks-->0)
    {
//    		n = in.nextLong();
//    		m = in.nextLong();
//    		K = in.nextLong();
        scanf("%lld%lld%lld",&n,&m,&K);
        mv=0;
        mr=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                scanf("%d",&l);
                dp[i][j] = dp[i][j-1] + l;
            }

        for(i=0;i<=m;i++)
            for(j=i;j<=m;j++)
            {
                cr=0;
                cv=0;
                l=1;
                for(k=1;k<=n;k++)
                {
                    cv+=dp[k][j] - dp[k][i];
                    cr+=j-i;

                    while(cv>K)
                    {
                        cv-=dp[l][j] - dp[l][i];
                        cr-=j-i;
                        l++;
                    }


                    if( cr == mr && cv<mv)	mv=cv;
                    if(cr>mr && cv<=K)
                    {
                        mr=cr;
                        mv=cv;
                    }

                }

            }

        //System.out.println("Case #"+ks+": "+mr+" "+mv);
        printf("Case #%d: %lld %lld\n",ks,mr,mv);
        ks++;
    }

    return 0;
}



