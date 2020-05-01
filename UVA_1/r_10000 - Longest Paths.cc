#include	<stdio.h>
#include	<queue>

int dis[102],adj[102][104],N,T,ma;
bool flag[102];

void INI()
{
	int i;
	for(i=1;i<N;++i)
	{
		adj[i][0] = 1;
		dis[i] = 0 ;
	}
	memset(flag,true,N);	
}

void DFS(int u,int d)
{		
	flag[u] = false;
	
	dis[u] = d;
	int i;
	for(i=1;i<adj[u][0];i++)
		if(flag[adj[u][i]] && d+1 > dis[adj[u][i]] )
		{
			//printf("\t\tu:%d v:%d\n",u,adj[u][i]);
			DFS(adj[u][i],d+1);	
		}
	flag[u] = true;
}

void G(int s)
{
	int i ;
	ma = 0;
	DFS(s,0);
	for(i=1;i<N;i++)
		if(dis[i]>ma)
		{
			ma =dis[i];
			T = i;			
		}
}

int main()
{
	int i,n,s,p,j,t=1,u,v;
	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)==1 && n)
	{
		N=n+1;
		INI();	
		
		scanf("%d",&s);
		while(scanf("%d%d",&u,&v) == 2 && (u||v))
			adj[u][ adj[u][0]++ ] = v;

		/*
		for(i=1;i<N;i++)
		{
			printf("i:%d\n",i);
			for(j=1;j<adj[i][0];j++)
				printf("%d ",adj[i][j]);
			printf("\n");
		}
		*/
		
		G(s);
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",t,s,ma,T);
		t++;
	}

	return 0 ; 
}
