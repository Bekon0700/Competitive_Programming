//BISMILLAHIRRAHMANIRROHIM
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
#define popcount(a)  (__builtin_popcount(a))
#define SZ(a)       ((int)a.size())
#define PB          push_back
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
#define SS			stringstream
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
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define p2(a)       (1LL<<(a))

int a[22],val,n;

bool mm[p2(19)+4][4];
bool tst[p2(19)+4][4];

bool go(int msk,int d)
{
    //printf("%d %d\n",msk,d);
    if(msk==p2(n)-1)    return true;

    if(tst[msk][d]) return mm[msk][d];

    tst[msk][d]=true;
    mm[msk][d]=false;

    int i,sum=a[n];
    bool f;

    for(i=0;i<n;i++)    if(msk&p2(i))    sum+=a[i];

    for(i=0;i<n;i++)
        if((msk&p2(i))==0 && sum+a[i]<=val*(d+1))
        {
            if(sum+a[i]==val*(d+1) )   f = go(msk|p2(i),d+1);
            else f = go(msk|p2(i),d);
            if(f)   return mm[msk][d]=true;
        }

    return mm[msk][d];
}

int main()
{
    int ks=1,i,sum;
    bool f;

    scanf("%d",&ks);

    while(ks--)
    {
        scanf("%d",&n);

        for(i=sum=0;i<n;scanf("%d",a+i),sum+=a[i],i++);

        f=true;
        val=sum/4;
        for(i=0;i<n&&f;i++)
            if(a[i]>val)
                f=false;

        if(sum%4 ||n<4 || !f) {printf("no\n");continue;}

        memset(tst,false,sizeof tst);

        n--;
        if(a[n]==val)   f=go(0,1);
        else f=go(0,0);

        if(f)   printf("yes\n");
        else printf("no\n");
    }

    return 0;
}




























