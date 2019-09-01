#include<stdio.h>

#define INF 10000

int mat[23][23];

void ini() 
{
	int i,j;
	for(i=1;i<21;i++)
	{		
		for(j=1;j<21;j++)	
			mat[i][j] = INF;
		mat[i][i] = 0;
	}
}

void fw()
{
	int i,j,k;
	
	for(k=1;k<21;k++)	
		for(i=1;i<21;i++)	
			for(j=1;j<21;j++)	
				if(mat[i][j] > mat[i][k] + mat[k][j])
					mat[i][j] = mat[i][k] + mat[k][j] ;
}

int main()
{
	int i,j,u,v,t=1,n;
	freopen("567.txt","r",stdin);
	while(scanf("%d",&n)==1)
	{
		ini();
		for(j=0;j<n;j++)
			{
				scanf("%d",&u);
				mat[u][1] = mat[1][u] = 1 ;
			}
		for(i=2;i<20;i++)
		{
			scanf("%d",&n);	
			for(j=0;j<n;j++)
			{
				scanf("%d",&u);
				mat[u][i] = mat[i][u] = 1 ;
			}
		}
		fw();
		scanf("%d",&n);
		printf("Test Set #%d\n",t++);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&u,&v);	
			printf("%2d to %2d: %d\n",u,v,mat[u][v]);
			
		}
		printf("\n");
	}
	
	return 0;
}
