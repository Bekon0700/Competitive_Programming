#include<stdio.h>

int mat[101][101];

int main()
{
	int i,j,n,N,k,c,max;
	
	
	while(scanf("%d",&n)==1)
	{
		N =n+1;
		for(i=0;i<n;i++)
			for(j=1;j<N;j++)
			{
				scanf("%d",&mat[i][j]);	
				mat[i][j] += mat[i][j-1];
			}
		for(i=1,max=0;i<N;i++)
			for(j=0;j<i;j++)
			{
				c=0;
				for(k=0;k<n;k++)				
				{
					c += mat[k][i] - mat[k][j];
					if(c < 0)					
						c = 0 ; 
					else if( c > max)
						max = c;
				}
			}
		printf("%d\n",max);	
	}

	return 0;
}
