#include	<stdio.h>
#include	<string.h>


int n,adj[101][101],stk[101],T,dg[101];
bool al[101];


void DV(int cn)
{
	al[cn] = false;

	for(int i=0;i<dg[cn];i++)
		if(al[adj[cn][i]])
			DV(adj[cn][i]);
	stk[++T] = cn;
}

void DFS()
{
	T=-1;
	for(int i=1;i<=n;i++)
		if(al[i])
			DV(i);

	printf("%d",stk[T--]);
	while(T>-1)
		printf(" %d",stk[T--]);
}

int main()
{
	int i,m,u,v;

	while(scanf("%d%d",&n,&m)==2 && (n||m))
	{
		memset(al,true,sizeof(al));
		memset(dg,0,sizeof(dg));
		
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			adj[u][dg[u]++] = v;
		}
		DFS();
		printf("\n");
	}

	return 0;
}