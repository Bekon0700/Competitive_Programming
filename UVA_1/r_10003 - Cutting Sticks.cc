#include<stdio.h>


int main()
{
	int p[53],mat[54][54],n,i,j,k,l,q,m;
	
	p[0]=0;
	while(scanf("%d",&l)==1 && l)
	{
		scanf("%d",&n);
		n++;
		for(i=1 ; i<=n ; i++ )
			mat[i][i] = 0 ;
		
		for(i=1;i<n;i++)
			scanf("%d",&p[i]);
		p[n] = l;
		
		for( l=2; l <= n ;l++)
    		for (i = 1 ; i <= n-l+1 ; i++ )
	   		{
				j = i + l - 1 ;
        		mat[i][j] = 2000000 ;
			
				for(k=i; k <= j-1 ; k ++ )
				{
	            	q = mat[i][k] + mat[k+1][j] - p[i-1] + p[j] ;
    	            if( q < mat[i][j] )
        	        	mat[i][j] = q;
				}
			
			}
	
		printf("The minimum cutting is %d.\n",mat[1][n]);
	}
	return 0;
}
