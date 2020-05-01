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

typedef struct{int i,j;}P;

char b[55][55];
int  nr,nc;
int xx[]={1,0,-1,0},
    yy[]={0,1,0,-1};

bool VDY(int i,int j){return (i>=0 && i<nr && j>=0 && j<nc);}

void BFS_X(int sr,int sc)
{
    int i,r,c;
    queue<int>q;

    b[sr][sc] = '*';
    q.push(sr);q.push(sc);

    while(!q.empty())
    {
        sr = q.front();q.pop();
        sc = q.front();q.pop();
        for(i=0;i<4;i++)
        {
            r = sr+xx[i];
            c = sc+yy[i];
            if(VDY(r,c) && b[r][c]=='X')
            {
                q.push(r);q.push(c);
                b[r][c] = '*';
            }
        }
    }
}

int BFS_S(int sr,int sc)
{
    int ret=0,i,r,c;
    queue<int>q;

    q.push(sr);
    q.push(sc);
    if(b[sr][sc]=='X')  {ret++;BFS_X(sr,sc);}
    b[sr][sc] = '.';

    while(!q.empty())
    {
        sr = q.front();q.pop();
        sc = q.front();q.pop();

        for(i=0;i<4;i++)
        {
            r = sr+xx[i];
            c = sc+yy[i];
            if(VDY(r,c) && b[r][c] != '.')
            {
                if(b[r][c]=='X'){ret++;BFS_X(r,c); }

                q.push(r);q.push(c);
                b[r][c] = '.';
            }
        }

    }
    return ret;
}

int main(){
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int ks=0,i,j,a[2505],k;
    bool tst;

    while(scanf("%d%d",&nc,&nr)==2 && (nr || nc))
    {

        rii(nr) scanf("%s",b[i]);
        tst =false;
        printf("Throw %d\n",++ks);
        k=0;
        rii(nr)rij(nc)  if(b[i][j] != '.' ) a[k++]=BFS_S(i,j);

        sort(a,a+k);
        rii(k)
        {
            if(i)printf(" ");
            printf("%d",a[i]);
        }
        printf("\n\n");
    }
    return 0;
}

