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

using namespace std;

#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          2*acos(0)
#define ERR         1e-5
#define SZ          size()
#define PB          push_back
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
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
#define APPRO(a,b)  ( (fabs(a-b)<ERR)?true:false )
#define PP(a)       (cout<<a<<endl)
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))

typedef struct{}P;

int main(){
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int i,n,t,w,z[100],k,d,j;
    bool dp[120];
    string v;
    char a[1000];

    scanf("%d\n",&t);

    while(t--)
    {

        gets(a);
        v.clear();
        v = a;
        ISS iss;
        OSS oss;
        oss<<v;
        iss.str(oss.str());
        w=0;
        k=0;
        while(iss>>d)
        {
            w+=d;
            z[k++] = d;

        }
        if(w&1)
        {
            printf("NO\n");continue;
        }
        w /= 2;
        memset(dp,false,sizeof(dp));
        dp[0]=true;

        rij(k)
        {
            rdi(w)
            if(dp[i] && i+z[j]<=w)
                dp[i+z[j]] = true;

        }

        if(dp[w])   printf("YES\n");
        else printf("NO\n");


    }


    return 0;
}

