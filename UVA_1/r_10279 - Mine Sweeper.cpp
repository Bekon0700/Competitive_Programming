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

int dx[]={1,1,1,0,0,-1,-1,-1},
    dy[]={1,0,-1,1,-1,-1,0,1};

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.in","w",stdout);

    int T,i,j,n,tt,c,k;

    char bo[12][12],p[12][12],out[12][12];

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);
        rii(n)  scanf("%s",bo[i]);
        rii(n)  scanf("%s",p[i]);
        mem(out,'.');
        tt=0;

        rii(n)rij(n)if(p[i][j]=='x')
        {
            if(bo[i][j]=='*')   tt=1;

            c=0;
            rik(8)
                if(i+dx[k]>-1 && i+dx[k]<n && j+dy[k]>-1 && j+dy[k]<n)
                    if(bo[i+dx[k]][j+dy[k]]=='*')   c++;
            out[i][j]=48+c;
        }

        if(tt)
        {
            //mem(out,'.');
            rii(n)rij(n)    if(bo[i][j]=='*')   out[i][j]='*';
        }

        rii(n)
        {
            rij(n)  printf("%c",out[i][j]);
            printf("\n");
        }

        if(T)   printf("\n");
    }


    return 0;
}


