#include<stdio.h>

int q[80000];

int main()
{
	int i,j,a[21],n,f,r,l,k,m,x,y,N;
	
	
	while(scanf("%d",&N)==1 && N)	
	{
		
		n = N +1 ;
		for( k = 2 ;  ; k ++ )
		{
			for(i=1,r=f=0;i<n;i++)
				q[ ++ r ] = i;
			
			while(r > f )
			{
				f++;
				j=1;
				if(r==f)
					break;
				while( j < k )
				{
					q[++r] = q[++f];	
					j++;
				}
				
			}
	
			if(q[f] == 2)
			{
				printf("%d\n",k);
				break;	
			}
		}	
		
	}
	return 0;
}
