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

#define oo          (1<<28)
#define PRE         1e-8
#define ERR         1e-5
#define PI          3.141592653589793
#define pi          2*acos(0)
#define PB          push_back
#define INS         insert
#define ISS         istringstream
#define OSS         ostringstream
#define LL          long long
#define LD          long double
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<LL>
#define IR          iterator
#define SZ          size()
#define fi(i,a,b)   for(i=a;i<b;i++)
#define fd(i,a,b)   for(i=a;i>b;i--)
#define fii(a,b)   for(i=a;i<b;i++)
#define fdi(a,b)   for(i=a;i>b;i--)
#define fij(a,b)   for(j=a;j<b;j++)
#define fdj(a,b)   for(j=a;j>b;j--)
#define fik(a,b)   for(k=a;k<b;k++)
#define fdk(a,b)   for(k=a;k>b;k--)
#define fil(a,b)   for(l=a;l<b;l++)
#define fdl(a,b)   for(l=a;l>b;l--)
#define ri(i,a)    for(i=0;i<a;i++)
#define rd(i,a)    for(i=a;i>-1;i--)
#define rii(a)     for(i=0;i<a;i++)
#define rdi(a)     for(i=a;i>-1;i--)
#define rij(a)     for(j=0;j<a;j++)
#define rdj(a)     for(j=a;j>-1;j--)
#define rik(a)     for(k=0;k<a;k++)
#define rdk(a)     for(k=a;k>-1;k--)
#define ril(a)     for(l=0;l<a;l++)
#define rdl(a)     for(l=a;i>-1;l--)
#define sqr(a)     (a*a)
#define EQ(a,b)    (fabs(a-b)<ERR)
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))

double r[8];
int per[9][50000][9],si[9],po[9];
bool fl[9];

void BT(int d,int n)
{
    int i;
    if(d==n)
    {
        rii(n)  per[n][si[n]][i] = po[i];   si[n]++;
    }
    rii(n)  if(fl[i]) {
        po[d] = i;
        fl[i] = false;
        BT(d+1,n);
        fl[i] = true;
    }
}

void GP()
{
    int i;
    memset(fl,true,sizeof(fl));
    fii(1,9)  BT(0,i);
}

double D(double r1,double r2)
{
    double a,b;
    a = r1+r2;
    b = fabs(r1-r2);
    return sqrt(sqr(a) - sqr(b));
}

int main()
{
    //freopen("in.in","r",stdin);
    int i,j,t,k,n;
    double s[8],m,x,y,d;

    GP();

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        m=0;
        rii(n)  {scanf("%lf",&r[i]);    m+=2*r[i];}

        rii(si[n])
        {
            rij(n)
            {
                s[j] = r[per[n][i][j]];
                rik(j)  s[j] = max(s[j],s[k]+D(r[per[n][i][j]],r[per[n][i][k]]));
            }
            d=0;
            rij(n)  d = max(d,r[per[n][i][j]]+s[j]);
            m = min(m,d);
        }
        printf("%.3lf\n",m);
    }

    return 0;
}

