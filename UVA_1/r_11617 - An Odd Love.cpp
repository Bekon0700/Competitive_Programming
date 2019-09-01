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
#define sz      1001
#define oo        (1<<30)
#define PI          3.141592653589793
#define pi          2*acos(0)
#define PB          push_back
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
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
template<class T>T sqr(T a) {return a*a;}

typedef long long LL;typedef vector<string>VS;typedef vector<int>VI;typedef vector<double>VD;typedef vector<long long>VLL;

char g[sz][sz];
int s[sz],e[sz],vs[sz],ve[sz];

int main(){
    int i,j,w,h,d,x,t,n;
    //freopen("in.in","r",stdin);

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&w,&h);
        rii(h)scanf("%s",g[i]);
        g[0][0] = '2';

        n=0;
        x=0;
        rii(h)
        {
            s[n] = -1;
            rij(w)  if(!(g[i][j]&1))   {s[n] = j;break;}
            if(s[n]>-1){
                e[n] = s[n];
                fij(j,w)  if(!(g[i][j]&1))   e[n]=j;
                n++;
                x = i;
            }
        }
        d = x;

        ve[0] = e[0] - s[0];vs[0] = 2*ve[0];
        //cout<<"vs "<<vs[0]<<"ve "<<ve[0]<<endl;

        fii(1,n)
        {
            ve[i] = min(vs[i-1]+e[i]-s[i]+abs(s[i-1]-s[i]), ve[i-1]+e[i]-s[i]+abs(e[i-1]-s[i]));
            vs[i] = min(vs[i-1]+e[i]-s[i]+abs(s[i-1]-e[i]), ve[i-1]+e[i]-s[i]+abs(e[i-1]-e[i]));
        }

        if(n>0){
            d += min(ve[n-1],vs[n-1]);
            //cout<<ve[n-1]<<endl;
        }
        printf("%d\n",d);
    }


    return 0;
}

