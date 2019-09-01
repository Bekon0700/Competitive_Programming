#include<stdio.h>

int main()
{
	int r[12],n,i,current,p[13],t=1;
	
	while(scanf("%d",&n)==1 && n > -1)
	{
		for(i=0;i<12;i++)
			scanf("%d",&p[i]);
		for(i=0;i<12;i++)
			scanf("%d",&r[i]);
		printf("Case %d:\n",t++);
		for(i=0;i<12;i++)
		{
			
			if( n < r[i] )			
				printf("No problem. :(\n");
			else
			{
				n -= r[i];
				printf("No problem! :D\n");	
			}
			n += p[i];
		}
		
	}


	return 0;
}
