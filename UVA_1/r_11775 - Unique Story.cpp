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

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
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
#define pair<int,int>   PII
#define pair<int,PII>   PIP


int cnt;
vector<int>A,B,C,D;
map<string,int>mp;
int mat[1010][1010],pmat[1010][1010];
LL p2[1012];
const LL M =  10000007;

vector<int> F(char a[])
{
    int i,j,l;
    vector<int>re;
    string s;
    l=strlen(a);
    for(i=0;i<l;i++)
        if(isalpha(a[i]))
        {
            s="";
            s+=a[i++];
                while(isdigit(a[i]))
                {
                    s+=a[i];
                    i++;
                }
                if(!mp[s])
                {
                    mp[s]=cnt++;
                }
                i--;
                re.push_back(mp[s]);
            }
    return re;
}


void LCS()
{
    int i,j,k,l;

    for(i=1;i<=SZ(B);i++)
        for(j=1;j<=SZ(A);j++)
        {
            if(A[j-1]==B[i-1])
            {
                mat[i][j] = (1+(2*mat[i-1][j-1]%M)%M)%M;
            }
            else
            {
                mat[i][j] = (2*M+mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1])%M;
            }

        }
}

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.in","w",stdout);
    LL i,j,k,n,ans,cm,m,nd,l;

    int tt,ks=1;
    p2[0] = 1;

    for(i=1;i<1005;i++)
        p2[i] = (p2[i-1]*2)%M;

    scanf("%d",&tt);
    string s;
    char a[4000],b[4000];

    while(tt--)
    {
        scanf("%s%s",a,b);
        cnt=1;
        mp.clear();
        C = F(a);
        D = F(b);
        A.clear();
        B.clear();
        for(i=0;i<SZ(D);i++)
            if(D[i]<=SZ(C))
            {
                //deb(D[i]);
                A.PB(D[i]);
                B.PB(D[i]);
            }
        sort(A.begin(),A.end());
        mem(mat,0);
        mem(pmat,0);
        LCS();
        ans = (p2[SZ(C)]+p2[SZ(D)]-2-2*mat[SZ(B)][SZ(A)]+2*M)%M;
        ans= (ans+M)%M;

        printf("Case %d: ",ks++);
        cout<<ans<<endl;

    }
    return 0;
}


