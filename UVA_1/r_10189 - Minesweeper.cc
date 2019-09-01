#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,N,M,w,f,t=0,m,n;
	char adj[110][110];

	while(true)
	{

		scanf("%d%d",&n,&m);
			if( !(m || n) )
				break;
		if(t)
			printf("\n");
		t++;

		for(i=0;i<n;i++)
			scanf("%s",adj[i]);
		printf("Field #%d:\n",t);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(adj[i][j] != '*')
					adj[i][j] = '0';
		N = n-1;
		M = m-1;
		for(i = 0 ; i < n ; i ++ )
			for(j = 0 ; j < m ; j ++ )
				if(adj[i][j] == '*')
				{
					if( i > 0 && j > 0)
						if(adj[i-1][j-1] != '*')
							adj[i-1][j-1]++;
					if( i > 0 )
						if(adj[i-1][j] != '*')
							adj[i-1][j]++;
					if( i > 0 && j < M)
						if(adj[i-1][j+1] != '*')
							adj[i-1][j+1]++;
					if( j > 0)
						if(adj[i][j-1] != '*')
							adj[i][j-1]++;
					if( j < M )
						if(adj[i][j+1] != '*')
							adj[i][j+1]++;
					if( i<N && j>0)
						if(adj[i+1][j-1] != '*')
							adj[i+1][j-1]++;
					if( i < N )
						if(adj[i+1][j] != '*')
							adj[i+1][j]++;
					if( i < N  && j < M)
						if(adj[i+1][j+1] != '*')
							adj[i+1][j+1]++;

				}
		for(i=0;i<n;i++)
			printf("%s\n",adj[i]);



	}
	return 0;
}


