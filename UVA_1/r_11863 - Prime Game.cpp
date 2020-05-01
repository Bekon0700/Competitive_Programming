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

int dp[110][110],a[160],cs[120];

bool f[100500];

void sieve()
{
    mem(f,false);
    int ss=100020,i,j,r;
    f[2]=true;
    for(i=3;i<ss;i+=2)  f[i] = true;

    for(i=3;i<ss;i+=2)
        if(f[i] && i<=ss/i)
            for(j=i*i,r=2*i;j<ss;j+=r)  f[j]=false;
}

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.in","w",stdout);
    sieve();
    int ks=1,tks,i,j,k,l,n,tst,sum,x,y;
    //rii(100)cout<<f[i]<<"  "<<i<<endl;

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d%d",&n,&k);
        tst=0;
        cs[0]=0;
        fii(1,n+1){
              scanf("%d",&a[i]);
              if(a[i]==42)tst=1;
              cs[i]=cs[i-1]+a[i];
        }
        //cout<<cs[4]-cs[2]<<endl;
        if(tst)
        {
            printf("Case %d: ",ks++);
            printf("Soha\n");
            continue;
        }

        mem(dp,0);

        fii(1,n+1)
            if(a[i] > 0)
                if(f[a[i]])
                    dp[i][i] = 1 ;

        for(l=2;l <= n;l++)
        {
            for(i=1;i <= n-l+1;i++)
            {
                j = i+l-1;
                sum=0;                for(k=i;k<=j;k++)   sum+=a[k];
                //sum = cs[j]-cs[i-1];
                if(sum>0)
                    if(f[sum])
                    {
                        dp[i][j]=1;
                        continue;
                    }
                for(k=i;k<j;k++)
                {
                    x = cs[k]-cs[i-1];
                    y = cs[j]-cs[k];
                    if(dp[i][k] && !dp[k+1][j] && x>0)
                    if(f[x])
                    {
                        dp[i][j]=1;
                        break;
                    }
                    if(!dp[i][k] && dp[k+1][j] && y>0)
                    if(f[y])
                    {
                        dp[i][j]=1;
                        break;
                    }
                }
            }
        }
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=n;j++)
//                printf("%d ",dp[i][j]);
//            cout<<endl;
//        }
        printf("Case %d: ",ks++);
        if(dp[1][n])    printf("Soha\n");
        else printf("Tara\n");

    }


    return 0;
}
/*
222
2 1
1 1
Case 1: Soha
2 3
2 3
Case 2: Tara


*/
