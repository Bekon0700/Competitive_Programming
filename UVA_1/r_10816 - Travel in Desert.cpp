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
#define PI          3.141592653589793
#define pi          2*acos(0)
#define ERR         1e-5
#define PRE         1e-8
#define SZ          size()
#define PB          push_back
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
#define EQ(a,b)     (fabs(a-b)<ERR)
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))


int dis[102],par[102];
VI adj[102],tem[102],pl[102];
struct pq{int d,t,u; bool operator <(const pq &b)const{ return t>b.t ;} };

int MMT(int s,int u)
{
	if(s==u)	return 0;
	else return max(dis[u],MMT(s,par[u]));
}

int PRIMS(int s,int d,int nv)
{

	priority_queue<pq>q;
	pq u,v;
	bool col[102];
	int i;

	rii(nv+1)
	{
		col[i] = true;
		dis[i] = oo;
	}
	u.u = s;
	u.t = dis[s] = 0;
	q.push(u);

	while(!q.empty())
	{
		u = q.top();q.pop();
		if(u.u == d)	return MMT(s,d);
		if(!col[u.u])	continue;
		col[u.u] = false;

		rii(adj[u.u].SZ)
			if(col[adj[u.u][i]] && dis[adj[u.u][i]] > tem[u.u][i])
			{
				v.u = adj[u.u][i];
				v.t = dis[adj[u.u][i]] = tem[u.u][i];
				par[v.u] = u.u;
				q.push(v);
			}
	}
}

int DIJ(int s,int d,int nv,int mt)
{

	priority_queue<pq>q;
	pq u,v;
	bool col[102];
	int i;

	rii(nv+1)
	{
		col[i] = true;
		dis[i] = oo;
	}
	u.u = s;
	u.t = dis[s] = 0;
	q.push(u);

	while(!q.empty())
	{
		u = q.top();q.pop();
		if(u.u == d)	return dis[d];
		if(!col[u.u])	continue;
		col[u.u] = false;
		rii(adj[u.u].SZ)
			if(col[adj[u.u][i]] && dis[adj[u.u][i]] > dis[u.u]+pl[u.u][i]  && tem[u.u][i]<=mt)
			{
				v.u = adj[u.u][i];
				v.t = dis[adj[u.u][i]] = dis[u.u]+pl[u.u][i];
				par[v.u] = u.u;
				q.push(v);
			}
	}
}

void PP(int s,int t)
{
	if(s==t) printf("%d",s);
	else
	{
		PP(s,par[t]);
		printf(" %d",t);
	}
}


int main(){
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
	int i,nv,ne,s,d,S,T,ans1,ans2,u,v;
	double l,t;

	while(scanf("%d%d",&nv,&ne)==2)
	{
		scanf("%d%d",&s,&d);

		rii(nv+1)
		{
			tem[i].clear();
			adj[i].clear();
			pl[i].clear();
		}
		rii(ne)
		{
			scanf("%d%d%lf%lf",&u,&v,&l,&t);
			T = l*10 + ERR;	S = t*10 +ERR;
			adj[u].PB(v); pl[u].PB(S); tem[u].PB(T);
			adj[v].PB(u); pl[v].PB(S); tem[v].PB(T);
		}
		ans2 = PRIMS(s,d,nv);
		ans1 = DIJ(s,d,nv,ans2);
		PP(s,d);
		printf("\n%.1lf %.1lf\n",(ans1/10.00),(ans2/10.00));

	}




    return 0;
}

