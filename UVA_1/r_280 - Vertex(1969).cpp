#include<iostream>

#define sz 101

bool mat[sz][sz];

void FloydWarshall(int n)
{
	int i,j,k;

	for(k=1;k<n;k++)
		for(i=1;i<n;i++)
			for(j=1;j<n;j++)
				if(mat[i][k] && mat[k][j])	
					mat[i][j] = true;

}

int main()
{
	int n,i,u,v,c,j;

	while(scanf("%d",&n)==1 && n)
	{
		n++;
		for(i=1;i<n;i++)
			memset(mat[i],false,sizeof(bool)*n);
		while(scanf("%d",&u)==1 && u)
		{
			while(scanf("%d",&v)==1 && v)
				mat[u][v] = true;
		}
		FloydWarshall(n);

		scanf("%d",&v);
		for(j=0;j<v;j++)
		{
			scanf("%d",&u);
			c=0;
			for(i=1;i<n;i++)
				if(!mat[u][i])
					c++;
			printf("%d",c);
		
			for(i=1;i<n;i++)
				if(!mat[u][i])
					printf(" %d",i);
			printf("\n");
		}
	}
	
	return 0;
}