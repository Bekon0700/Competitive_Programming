#include<stdio.h>

int q[20000];

int main()
{
	int i,j,a[21],n,f,r,l,k,m,x,y;
	
	
	while(scanf("%d",&n)==1 && n)	
	{
		n ++ ;
		for( k = 1 ;  ; k ++ )
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
	
			if(q[f] == 13)
			{
				printf("%d\n",k);
				break;	
			}
		}	
		
	}
	return 0;
}
