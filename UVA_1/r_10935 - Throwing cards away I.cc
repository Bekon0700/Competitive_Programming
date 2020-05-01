#include<stdio.h>

int q[20000];

int main()
{
	int i,j,a[21],n,f,r;
	
	
	while(scanf("%d",&n)==1 && n)	
	{
		n ++ ;
		f = r = 0 ;
		for(i=1;i<n;i++)
			q[ ++ r ] = i;
		i=0;
		printf("Discarded cards:");
		if(n-2)
		{
			while(r - 1 > f )
			{
				if(i++)
				printf(",");
				printf(" %d",q[++f]);
				q[++r] = q[++f];	
			}
			printf("\n");
			printf("Remaining card: %d\n",q[f]);
			
		}	
		else
			printf("\nRemaining card: 1\n");
	}
	return 0;
}
