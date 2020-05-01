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
#define pair<int,int>   PII
#define pair<int,PII>   PIP


int m(string s)
{
    if(s=="Ja") return 0;
    if(s== "Sam") return 1;
    if(s=="Sha") return 2;
    if(s=="Sid") return 3;
    if(s=="Tan") return 4;

}


int main()
{
    //freopen("in.in","r",stdin);
    int ks=1,i,j,TT,N,M,f,ch,c;
    int tm[5];
    string s;


    cin>>TT;

    while(TT--)
    {
        cin>>M>>N>>s;
        mem(tm,0);
        ch = m(s);

        queue<int>q[5];

        for(i=0;i<5;i++)
        {
            cin>>c;
            for(j=0;j<c;j++)
            {
                cin>>s;
                q[i].push(m(s));
            }
        }

        c=0;

        while(true)
        {
            f = ch;
            if(c+M<=N)
                tm[f] += M;
            else if(c<N)    tm[f] +=N-c;
            else break;
            c+=M+2;
            q[f].push(q[f].front());
            ch  = q[f].front();
            q[f].pop();
        }
        printf("Case %d:\n",ks++);
        printf("Ja %d\nSam %d\nSha %d\nSid %d\nTan %d\n",tm[0],tm[1],tm[2],tm[3],tm[4]);

    }
    return 0;
}


