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
#define INF 90000000

using namespace std;

int chk[10000];
int r,c,k;
string sm[16][16],ps="ENSW",f;
int par[25][25],x[13],y[13];
int dm[13][13],n,m;
int dx[]={0,-1,1,0};
int dy[]={1,0,0,-1};
char lnd[25][25];

int p[30];
int dis[30][30];
int True;
struct ss
{
    int x,y,c;
    string st;
};

ss A[30];
int N;

struct xx
{
    int pos,cost,bit;
    string st;
};

vector<xx>Ed[400];
int P[400],rank[400];

void ini()
{
 int i;
 for(i=0;i<=N;i++)
 P[i]=i,rank[i]=0;
}

int find(int x)
{
 if(P[x]!=x)
 P[x]=find(P[x]);
 return P[x];
}

void link(int x,int y)
{
 if(rank[x]>rank[y])
 P[y]=x;
 else
 {
  P[x]=y;
  if(rank[x]==rank[y])
  rank[y]++;
 }

}


void BFS(int s)
{
    int i,ux,uy,vx,vy;
    queue<int>q;
    mem(dis,1);
    mem(par,-1);

    dis[x[s]][y[s]]=0;
    par[x[s]][y[s]]=4;
    q.push(x[s]);
    q.push(y[s]);

    while(!q.empty())
    {
        ux=q.front();q.pop();
        uy=q.front();q.pop();

        rii(4)
        {
            vx=ux+dx[i];
            vy=uy+dy[i];
            if(vx>-1 &&vy>-1 && vx<r && vy<c &&(lnd[vx][vy]=='#' || isalpha(lnd[vx][vy]))
            && dis[ux][uy]+1<dis[vx][vy])
            {
                par[vx][vy] = i;
                dis[vx][vy] = 1+dis[ux][uy];
                q.push(vx);
                q.push(vy);
            }
        }
    }
}

void PP(int ux,int uy,int vx,int vy,int s,int d)
{
    //m++;    if(m==16)    return;
    //cout<<ux<<" "<<uy<<" "<<vx<<" "<<vy<<"\n";
    if(ux==vx && uy==vy) return;
    //cout<<m<<endl;
    int k=par[vx][vy];
    PP(ux,uy,vx-dx[k],vy-dy[k],s,d);
    sm[s][d]+=ps[k];
}


int e;
ss Edge[10000];
int fao;

int D[15][10000];
string M[15][5000];
//bool flg[15][10000];
//string dd[15][5000];

int cmp(const void *a,const void *b)
{
     ss *X=(ss *)a;
     ss *Y=(ss *)b;
     if(X->c>Y->c) return 1;
     else if(X->c<Y->c) return -1;
     else
     {
        int pq=X->st.compare(Y->st);
        if(pq>0) return 1;
        else if(pq<0) return -1;
        else return 0;
     }
}




/*
class com
{
public : bool operator()(const xx &a,const xx &b)
{
    if(a.cost!=b.cost) return a.cost>b.cost;
    else
    {
        int pr=a.st.compare(b.st);
        if(pr>0) return true;
        return false;
    }
}
};

int out(int bit)
{
    int p=0;
    while(bit)
    {
        if((bit&1)==1) p++;
        bit=(bit>>1);
    }
    return p;
}



void dijk()
{
    int i,j;
    for(i=0;i<=N;i++)
    {
        for(j=0;j<(1<<N);j++) D[i][j]=INF,M[i][j].clear();
    }
    priority_queue<xx,vector<xx> ,com>Q;
    xx x1,x2,x3;
    x1.cost=0,x1.pos=0,x1.st.clear();x1.bit=1;
    Q.push(x1);
    while(!Q.empty())
    {
        x1=Q.top();
        //deb(x1.pos);
        //printf("%c\n",grid[A[x1.pos].x][A[x1.pos].y]);
        Q.pop();
        if(x1.pos==1&&out(x1.bit)==k+2)
        {
            cout<<x1.st<<endl;
            return ;
        }
        //deb(Ed[x1.pos].size());
        for(i=0;i<Ed[x1.pos].size();i++)
        {
            x3=Ed[x1.pos][i];
            x2.bit=((x1.bit)|(1<<(x3.pos)));
            x2.pos=x3.pos;x2.cost=x1.cost+x3.cost;x2.st=x1.st+x3.st;
            //printf("%d %d\n",D[x2.pos][x2.bit],x2.cost);
            if(D[x2.pos][x2.bit]>x2.cost)
            {
                D[x2.pos][x2.bit]=x2.cost;
                M[x2.pos][x2.bit]=x2.st;
                Q.push(x2);
                //printf("1->%c\n",grid[A[x2.pos].x][A[x2.pos].y]);
            }
            else if(D[x2.pos][x2.bit]==x2.cost)
            {
                int ps=M[x2.pos][x2.bit].compare(x2.st);
                if(ps>0)
                {
                    D[x2.pos][x2.bit]=x2.cost;
                    M[x2.pos][x2.bit]=x2.st;
                    Q.push(x2);
                    //printf("->%c\n",grid[A[x2.pos].x][A[x2.pos].y]);
                }
            }

        }
    }

}

*/
/// MY DIJ



struct pq
{
    int vn,msk,d;
    string cst;

    bool operator<(const pq &b)const
    {
        if(d!=b.d)   return d>b.d;
        return cst>b.cst;
    };
};



void DIJ(int mym)
{
    string s;
    int oo,i,msk,cos,j;
    pq u,v;
    priority_queue<pq>Q;



    for(i=0;i<=N;i++)
    {
        for(j=0;j<(1<<N);j++) D[i][j]=INF,M[i][j].clear();
    }

    u.d=D[0][p2(0)]=0;
    u.vn = 0;
    u.msk = p2(0);
    u.cst=M[0][p2(0)]="";

    Q.push(u);

    while(!Q.empty())
    {
        u = Q.top();
        Q.pop();

        if(__builtin_popcount(u.msk)==k+2 && u.vn==1 )
        {
            cout<<u.cst<<endl;
            return ;
        }


        for(i=0;i<N;i++) //if((u.msk&p2(i)) == 0)
        {
            if(SZ(sm[u.vn][i])>mym)  continue;

            s = M[u.vn][u.msk]+sm[u.vn][i];
            cos = D[u.vn][u.msk]+SZ(sm[u.vn][i]);
            msk = (u.msk|p2(i));
            if(D[i][msk]>cos)
            {
                v.d=D[i][msk]=cos;
                v.msk = msk;
                v.vn=i;
                v.cst= M[i][msk] = s;
                Q.push(v);
            }
            else if(D[i][msk]== cos && M[i][msk]>s)
            {
                v.d=D[i][msk]=cos;
                v.msk = msk;
                v.vn=i;
                v.cst= M[i][msk] = s;
                Q.push(v);
            }
        }
    }
}









int main()
{
    //freopen("D.in","r",stdin);
    xx x1,x2;
    int i,j,mx,a1,b1;
    while(scanf("%d%d%d",&r,&c,&k)==3)
    {
        N=2;e=0;

        rii(r)  scanf("%s",lnd[i]);
        rii(400)    Ed[i].clear();

        for( i=0;i<r;i++) {

            for( j=0;lnd[i][j]!=0;j++)
            {
                if(lnd[i][j]=='S') A[0].x=i,A[0].y=j,x[0]=i,y[0]=j;
                else if(lnd[i][j]=='T') A[1].x=i,A[1].y=j,x[1]=i,y[1]=j;
                else if(lnd[i][j]>='A'&&lnd[i][j]<='Z') {A[N].x=i,A[N].y=j,x[N]=i,y[N]=j;N++;};
            }
        }

        //cout<<"here"<<endl;

        for( i=0;i<N;i++)
        {
            BFS(i);
            for( j=0;j<N;j++)
            {
                if(i==j) continue;
                sm[i][j]="";

                //cout<<A[i].x<<" "<<A[i].y<<" "<<A[j].x<<" "<<A[j].y<<endl;
                PP(x[i],y[i],x[j],y[j],i,j);
                Edge[e].x=i;
                Edge[e].y=j;
                Edge[e].c=SZ(sm[i][j]);
                Edge[e].st=sm[i][j];
                e++;
            }
        }

        //cout<<N<<" "<<e<<endl;

        qsort(Edge,e,sizeof(ss),cmp);
        ini();
         mx=0;True++;
        for( i=0;i<e;i++)
        {
             a1,b1;
            a1=find(Edge[i].x);b1=find(Edge[i].y);
            if(a1!=b1)
            {
                link(a1,b1);
                x1.cost=Edge[i].c;x1.st=Edge[i].st;
                x1.pos=Edge[i].y;
                Ed[Edge[i].x].push_back(x1);
                //printf("%c %c\n",grid[A[Edge[i].x].x][A[Edge[i].x].y],grid[A[Edge[i].y].x][A[Edge[i].y].y]);
                //printf("i:%d pos:%d cost:%d %s\n",Edge[i].x,x1.pos,x1.cost,x1.st.c_str());
               /* x1.pos=Edge[i].x;
                reverse(x1.st.begin(),x1.st.end());
               Ed[Edge[i].y].push_back(x1);*/
               //printf("here\n");
                //cout<<Edge[i].x<<" "<<Edge[i].y<<" "<<x1.cost<<" "<<x1.st<<endl;
                mx=max(mx,x1.cost);
                chk[i]=True;
            }

        }
        for( i=0;i<e;i++)
        {
            if(chk[i]==True) continue;
            if(Edge[i].c<=mx)
            {
                x1.cost=Edge[i].c;x1.st=Edge[i].st;
                x1.pos=Edge[i].y;
                Ed[Edge[i].x].push_back(x1);
            //printf("%c %c\n",grid[A[Edge[i].x].x][A[Edge[i].x].y],grid[A[Edge[i].y].x][A[Edge[i].y].y]);
            //printf("i:%d pos:%d cost:%d %s\n",Edge[i].x,x1.pos,x1.cost,x1.st.c_str());
                /*x1.pos=Edge[i].x;
                reverse(x1.st.begin(),x1.st.end());
               Ed[Edge[i].y].push_back(x1);*/
               //printf("here\n");
                //cout<<Edge[i].x<<" "<<Edge[i].y<<" "<<x1.cost<<" "<<x1.st<<endl;
               // mx=max(mx,x1.cost);
            }
        }
        //m=mx;
        //deb(m);

        //dijk();
        DIJ(mx);

    }
    return 0;
}
