#include<iostream>

#define sz 251
#define inf 20000991


int n,mat[sz][sz],cf[sz],f[sz];

int main()
{
	int i,j,k,l,q,n;

	while(scanf("%d",&n)==1)
	{
		
		for(i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);
			cf[i] = cf[i-1]+f[i];
		}

		for(l=2;l<=n;l++)
		{
			for(i=1;i<=n-l+1;i++)
			{
				j = i+l-1;
				mat[i][j]= inf;
				for(k=i+1;k<j;k++)
				{
					 q = mat[i][k-1]+mat[k+1][j]+cf[k-1]-cf[i-1]+ cf[j]-cf[k];
					 if(q<mat[i][j])
						 mat[i][j] = q;
				}
				k=i;
				q = mat[k+1][j]+cf[j]-cf[k];
				if(q<mat[i][j])
					mat[i][j] = q;
				k=j;
				q = mat[i][k-1]+cf[k-1]-cf[i-1];
				if(q<mat[i][j])
					mat[i][j] = q;
			}

		}
		printf("%d\n",mat[1][n]);
	}

	return 0;
} 