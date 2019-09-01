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
#define accu(a,b,c) accumulate((a),(b),(c))
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


typedef struct {LL x1,y1,x2,y2;}M;
M m[102],sd,be;
LL x[1000],y[1000],nm,np,D[1030][1030],nx,ny;
map<LL,LL>MX,MY;

bool col[1010][1010];

LL ABS(LL a){if(a<0) return -a;return a;}
struct pq{LL xi,yi,d;bool operator<(const pq &b)const{return d>b.d;}};


void DIJ()
{
    LL oo,i,cst;
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};

    mem(&oo,30);
    mem(D,30);

    priority_queue<pq>q;
    pq u,v;

    D[be.x1][be.y1]=0;

    q.push((pq){be.x1,be.y1,0});

    while(!q.empty())
    {
        //cout<<x[u.n]<<" "<<y[u.n]<<endl;
        u=q.top();  q.pop();
        if(u.xi==be.x2&&u.yi==be.y2)  break;
        if(col[u.xi][u.yi])    continue;
        col[u.xi][u.yi]=true;

        rii(4)
        {
            v.xi=u.xi+dx[i];
            v.yi=u.yi+dy[i];
            if(v.xi<0 || v.yi<0 || v.xi>=nx || v.yi>=ny || col[v.xi][v.yi]) continue;
            cst = ABS(x[u.xi]-x[v.xi])+ABS(y[u.yi]-y[v.yi]);

            if(D[v.xi][v.yi]>u.d+cst)
            {
                v.d=D[v.xi][v.yi]=u.d+cst;
                q.push(v);
            }
        }

    }
    //cout<<dis[1]<<endl;
    if(D[be.x2][be.y2]<oo)   printf("%lld\n",D[be.x2][be.y2]);
    else printf("Impossible\n");
}


int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.in","w",stdout);
    int ks=1,tks,i,j,k,x1,x2,y1,y2,p,s,r;
    LL ad=1000000000;

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

        sd.x1=x1+ad;sd.y1=y1+ad;sd.x2=x2+ad;sd.y2=y2+ad;

        x[0]=ad+x1;
        y[0]=ad+y1;
        x[1]=ad+x2;
        y[1]=ad+y2;

        scanf("%d%d%d",&p,&s,&r);

        np=2;
        nm=0;

        rii(p)
        {
            scanf("%d%d",&x1,&y1);
            x2=x1;
            y2=y1;
            m[nm].x1=ad+min(x1,x2);
            m[nm].y1=ad+min(y1,y2);
            m[nm].x2=ad+max(x1,x2);
            m[nm].y2=ad+max(y1,y2);
            x[np]=x1+ad;
            y[np++]=y1+ad;

            if(0<=m[nm].x1-1 && 0<=m[nm].y1-1)    {x[np]=m[nm].x1-1;y[np]=m[nm].y1-1;np++;}
            if(2*ad>=m[nm].x2+1 && 0<=m[nm].y1-1)    {x[np]=m[nm].x2+1;y[np]=m[nm].y1-1;np++;}
            if(2*ad>=m[nm].x2+1 && 2*ad>=m[nm].y2+1)    {x[np]=m[nm].x2+1;y[np]=m[nm].y2+1;np++;}
            if(0<=m[nm].x1-1 && 2*ad>=m[nm].y2+1)    {x[np]=m[nm].x1-1;y[np]=m[nm].y2+1;np++;}
            nm++;
        }


        rii(s)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

            m[nm].x1=ad+min(x1,x2);
            m[nm].y1=ad+min(y1,y2);
            m[nm].x2=ad+max(x1,x2);
            m[nm].y2=ad+max(y1,y2);

            x[np]=x1+ad;
            y[np++]=y1+ad;
            x[np]=x2+ad;
            y[np++]=y2+ad;

            if(0<=m[nm].x1-1 && 0<=m[nm].y1-1)    {x[np]=m[nm].x1-1;y[np]=m[nm].y1-1;np++;}
            if(2*ad>=m[nm].x2+1 && 0<=m[nm].y1-1)    {x[np]=m[nm].x2+1;y[np]=m[nm].y1-1;np++;}
            if(2*ad>=m[nm].x2+1 && 2*ad>=m[nm].y2+1)    {x[np]=m[nm].x2+1;y[np]=m[nm].y2+1;np++;}
            if(0<=m[nm].x1-1 && 2*ad>=m[nm].y2+1)    {x[np]=m[nm].x1-1;y[np]=m[nm].y2+1;np++;}
            nm++;
        }

        rii(r)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

            m[nm].x1=ad+min(x1,x2);
            m[nm].y1=ad+min(y1,y2);
            m[nm].x2=ad+max(x1,x2);
            m[nm].y2=ad+max(y1,y2);


            x[np]=x1+ad;
            y[np++]=y1+ad;
            x[np]=x2+ad;
            y[np++]=y2+ad;

            if(0<=m[nm].x1-1 && 0<=m[nm].y1-1)    {x[np]=m[nm].x1-1;y[np]=m[nm].y1-1;np++;}
            if(2*ad>=m[nm].x2+1 && 0<=m[nm].y1-1)    {x[np]=m[nm].x2+1;y[np]=m[nm].y1-1;np++;}
            if(2*ad>=m[nm].x2+1 && 2*ad>=m[nm].y2+1)    {x[np]=m[nm].x2+1;y[np]=m[nm].y2+1;np++;}
            if(0<=m[nm].x1-1 && 2*ad>=m[nm].y2+1)    {x[np]=m[nm].x1-1;y[np]=m[nm].y2+1;np++;}
            nm++;
        }

        sort(x,x+np);
        sort(y,y+np);

//        rii(nm) cout<<"mon:"<<m[i].x1<<" "<<m[i].y1<<" "<<m[i].x2<<" "<<m[i].y2<<"\n";
//
//        rii(np) cout<<i<<" po: "<<x[i]<<" "<<y[i]<<endl;
        MX.clear();
        nx=0;
        rii(np)
        {
            if(i&&x[i]==x[i-1]) continue;


            x[nx]=x[i];
            if(sd.x1==x[nx]) be.x1=nx;
            if(sd.x2==x[nx]) be.x2=nx;
            MX[x[i]]=nx++;
        }

        MY.clear();
        ny=0;
        rii(np)
        {
            if(i&&y[i]==y[i-1]) continue;
            y[ny]=y[i];
            if(sd.y1==y[ny]) be.y1=ny;
            if(sd.y2==y[ny]) be.y2=ny;

            MY[y[i]]=ny++;
        }

        mem(col,false);

        rii(nm)
        {
            x1=MX[m[i].x1];
            y1=MY[m[i].y1];
            x2=MX[m[i].x2];
            y2=MY[m[i].y2];
            fij(x1,x2+1)
                fik(y1,y2+1)
                    col[j][k]=true;

        }

        printf("Case %d: ",ks++);
        DIJ();
    }


    return 0;
}


