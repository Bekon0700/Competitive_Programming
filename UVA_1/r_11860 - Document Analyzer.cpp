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
#define NL          (cout<<endl)

int ar[120000],l[120000];
char line[200];
map<string,int>ms;

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.in","w",stdout);
    int tks,ks=1,i,j,k,m,a,b,ind,nw;
    string s;

    scanf("%d\n",&tks);

    while(tks--)
    {
        ms.clear();
        ind = 1;
        nw=1;

        while(gets(line))
        {
            if(!strcmp(line,"END")) break;
            for(i=0;line[i];i++)    if(!islower(line[i]))   line[i]=' ';
            SS ss;
            ss<<line;

            while(ss>>s)
            {
                if(!ms[s])
                    ar[ind++] = ms[s]=nw++;
                else ar[ind++] = ms[s];
            }
        }
        //fii(1,ind)  cout<<ar[i]<<" ";   NL;
        mem(l,0);
        m=ind;
        j=a=1;
        b=ind-1;

        fii(1,ind)
        {
            ar[l[ar[i]]] = -1;
            l[ar[i]]=i;
            while(ar[j]==-1)    j++;
            if(l[nw-1] && i-j+1<m )
            {
                m=i-j+1;
                a=j;
                b=i;
            }
        }
        printf("Document %d: %d %d\n",ks++,a,b);
    }
    return 0;
}

