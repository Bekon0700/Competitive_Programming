#include<stdio.h>
#include<string.h>

int cost[1002][1002],list[1002][1002],deg[1002],n,dis[1002]; 

bool  BELLMANFORD()
{
	int i,j,k;
	for(i=0;i<n;i++)
		dis[i] = 33554432;
	dis[0]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<deg[i];j++)	
			if(dis[list[i][j]] > dis[i] + cost[i][list[i][j]])
			{
				dis[list[i][j]] = dis[i] + cost[i][list[i][j]];
			}
	}

	for(i=0;i<n;i++)
		for(j=0;j<deg[i];j++)
			if(dis[list[i][j]] > dis[i] + cost[i][list[i][j]])
				return true;
			
	return false;
}


int main()
{
	int j,i,k,m,u,v,w,t;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);	
		memset(deg,0,n*sizeof(int));

		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);	
			list[u][ deg[u]++ ]= v;
			cost[u][v] = w;
		}

		if(BELLMANFORD())
			printf("possible\n");
		else
			printf("not possible\n");
	}
	return 0;
}
