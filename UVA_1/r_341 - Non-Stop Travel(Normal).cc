#include	<stdio.h>

#define INF 20000000
#define  P(a)	a>>1
#define  L(a)	a<<1
#define  R(a)	(a<<1)+1

int mat[12][12],par[12],dis[12],s,t,pr[12],tp;
bool tst[12] ;

void ini(int n)
{
	int i,j;

	for(i=1;i<n;i++)	
	{
		for(j=1;j<n;j++)		
			mat[i][j] = INF;
		par[i] = dis[i] = INF;
		mat[i][i] = 0;
		tst[i] = true;
	}
}

void DIJKSTRA(int n)
{
	dis[s] = 0;
	tst[s] = false;
	
	int i,l,u=s,min=0;
	
	while(u)
	{
		for(i=1;i<n;i++)
			if(dis[i] > dis[u] + mat[u][i])
			{
				par[i] = u;	
				dis[i] = dis[u]+mat[u][i];
			}
		for(i=u=0,min=INF;i<n;i++)
			if( dis[i] < min && tst[i])
			{
				u = i;	
				min = dis[i];
			}
		tst[u] = false;
	}
	
	tp = 0;
	i = t;

	while(i != INF)
	{
		pr[++tp] = i;	
		i = par[i] ;
	}
	
	if(s==t)  printf(" %d",s);
 	while(tp)
		printf(" %d",pr[tp--]);
}

int main()
{
	int i,j,k=1,n,m,u,v,w;
	
	while(scanf("%d",&n)==1 && n)
	{
		ini(n+1);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&m);	
			for(i=0;i<m;i++)
			{
				scanf("%d%d",&v,&w);	
				mat[j][v] = w;
				
			}
			
		}
		scanf("%d%d",&s,&t);
		printf("Case %d: Path =",k++);
		DIJKSTRA(n+1);
		printf("; %d second delay\n",dis[t]);
	}		

	return 0;
}
