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
#define ERR         1e-5
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
#define V 1001
struct pq{int n,c;bool operator <(const pq &b)const{return c>b.c;}};
bool col[V],ero;
int mat[V][V],n,tax[V],par[V],dis[V];
vector<pq> adj[V];

void PRINT_PATH(int t,int s)
{
    if(t==s)
        printf("%d",t);
    else
    {
        PRINT_PATH(par[t],s);
        printf("-->%d",t);
    }
}

void DIJKSTRA(int s,int t)
{
    int cost=0,i,j;
    pq u,v;
    priority_queue<pq>Q;
    memset(par,-1,sizeof(par));
    dis[s] = 0;
    u.n=s; u.c=0;   Q.push(u);
    par[s]=-1;

    while(!Q.empty())
    {
        u = Q.top();  Q.pop();

        if(col[u.n])
        {
            col[u.n] = false;
            for(i=0;i<adj[u.n].size();i++)
                if(col[adj[u.n][i].n])
                {
                    v = adj[u.n][i];
                    cost=v.c;
                    if(v.n!=t)    cost+=tax[v.n];
                    if(u.c+cost<dis[v.n])
                    {
                        v.c=dis[v.n]=u.c+cost;
                        par[v.n]=u.n;
                        Q.push(v);
                    }
                }
        }
    }
    //fii(1,n+1)printf("%d %d\n",i,dis[i]);
    printf("From %d to %d :\n",s,t);
    printf("Path: ");
    PRINT_PATH( t,s);
    printf("\nTotal cost : %d\n",dis[t]);
}

int main(){
    //freopen("in.in","r",stdin);
    int i,j,l,c,s,t,ks=1,cs,kk=0;
    char a[10000];
    string st;
    ISS iss;
    pq u;

    scanf("%d\n\n",&cs);
    fil(1,cs+1)
    {

        adj[1].clear();
        gets(a);
        iss.clear();
        iss.str(a);
        n=0;

        while(iss>>c)
        {
            n++;
            if(c!=-1)
            {
                u.n=n;u.c=c;
                adj[1].PB(u);
            }
        }
        fii(2,n+1)
            {
                adj[i].clear();
                gets(a);
                iss.clear();
                iss.str(a);
                fij(1,n+1)
                {
                    iss>>c;

                    if(c!=-1)
                    {
                        u.n=j;u.c=c;
                        adj[i].PB(u);
                    }
                }
            }
        gets(a);
        iss.clear();
        iss.str(a);
        fii(1,n+1)
        {
            iss>>tax[i];
        }


        while(gets(a))
        {
            if(!strcmp(a,""))   break;
            iss.clear();
            iss.str(a);
            iss>>s>>t;
            //cout<< s<< t <<endl;
            rii(n+1)    {dis[i]=oo;col[i]=true;}
            if(kk++) printf("\n");
            DIJKSTRA(s,t);

        }

    }
    return 0;
}

