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

#define oo        (1<<30)
#define PI          3.141592653589793
#define pi          2*acos(0)
#define PB          push_back
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define ISS         istringstream
#define OSS         ostringstream
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
typedef struct {int a;}P;
P p;

int x[2001],y[2001];

int main(){
    int i,j,t=1,maxx,maxy,miny,minx,n,c,r,ax,ay;
    bool zx[5],al;
    //freopen("in.in","r",stdin);

    while(scanf("%d%d%d",&n,&c,&r)==3&&(n||r||c))
    {

            zx[4]=zx[3]=zx[2]=zx[1]=zx[0]=true;
            al=true;

            rii(r){
                scanf("%d%d",&x[i],&y[i]);
            }
            scanf("%d%d",&ax,&ay);
            if(!ax) zx[1]=false;
            if(!ay) zx[3]=false;
            if(ax+1==n) zx[2]=false;
            if(ay+1==c) zx[4]=false;

            rii(r){
                if(ax==x[i]|| ay==y[i])zx[0] =false;
                if(ax-1==x[i] || ay==y[i] )zx[1] =false;
                if(ax+1==x[i]|| ay==y[i])zx[2] =false;
                if(ay-1==y[i] || ax==x[i])zx[3] =false;
                if(ay+1==y[i] || ax==x[i])zx[4] =false;
            }
        rii(5)if(zx[i])
        {
            //printf("%d\n",i);
            printf("Case %d: Escaped again! More 2D grid problems!\n",t++);al=false;break;}

        if(al)
        printf("Case %d: Party time! Let's find a restaurant!\n",t++);
    }


    return 0;
}
