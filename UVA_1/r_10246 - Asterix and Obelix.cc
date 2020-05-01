#include	<stdio.h>

#define		INF		3000000000

long long mat[90][90],par[90][90],fc[90],fmat[90][90];

void ini(long long n)
{
	long long i,j;
	for(i=1;i<n;i++)
		for(j=1;j<n;j++)
		{
			mat[i][j] = INF;
			fmat[i][j]=par[i][j] = 0 ;
		}
	for(i=1;i<n;i++)
	{
		mat[i][i] = 0 ;
		
	}
}

void f(long long n)
{
	long long i,j,k;
	for(i=1;i<n;i++)
		for(j=1;j<n;j++)
			if(mat[i][j] < INF)
			{
				if(fc[i] > fc[j])
					fmat[i][j] = fc[i];
				else
					fmat[i][j] = fc[j];
			}
}

void floyed(long long n)
{
	long long  i,j,k,max;
	
	for(k=1;k<n;k++)	
		for(i=1;i<n;i++)	
			for(j=1;j<n;j++)
			{
				if(fmat[i][k] > fmat[k][j])	max = fmat[i][k];
				else 	max = fmat[k][j];
				if( mat[i][j] + fmat[i][j] > mat[i][k] + mat[k][j] + max )
				{
					mat[i][j] = mat[i][k] + mat[k][j] ;
					fmat[i][j] = max;
				}
			}				
}


int main()
{
	long long n,m,q,i,j,k,u,v,x,N,s,cas=1,t=0;
	
	while(scanf("%lld%lld%lld",&n,&m,&q)==3 && (n||m||q))
	{
		if(t)	printf("\n");
		t ++ ;
		N=n+1;
		ini(N);
		for(i=1;i<N;i++)
			scanf("%lld",&fc[i]);
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&u,&v,&s);	
			mat[v][u] = mat[u][v] = s;
		}
		f(N);
		floyed(N);
		floyed(N);
		printf("Case #%lld\n",cas++);
		
		for(i=0;i<q;i++)
		{
			scanf("%lld%lld",&u,&v);	
			x = fmat[u][v]+mat[u][v];
			if(x<INF)
				printf("%lld\n",x);
			else
				printf("-1\n");	
		}
	}
}
