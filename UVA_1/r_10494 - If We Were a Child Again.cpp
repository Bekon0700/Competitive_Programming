#include<stdio.h>
#include<string.h>

int main()
{
	long long  i,j,k,x,m,sec,l,t=0;

	char o[3],r[10000],first[10000];
																																																																																				
	
	while(scanf("%s%s%lld",first,o,&sec)==3)
	{
		
		if(o[0] == '%')		
		{
			l = strlen(first) ;	
			for(i=x=0 ; i < l ; i ++ )
			{
				x = x * 10 + (first[i] - 48) ;
				x %= sec;
			}
			x %= sec; 
			printf("%lld",x);
			
		}
		else 
		{
			
			l = strlen(first);	
			
			for(i=0;first[i] == '0';)	i++;
			
			for(x=m=0;i<l;i++)
			{
				x = x * 10 + (first[i] - 48) ;
				
				if( (x/sec) || m)
				{
					printf("%d",x/sec);	
					m = 1 ;
				}
				x %= sec ;
			}			
			
			if(!m)
				printf("0");
		}
		printf("\n");
	}	
	
	return 0;
}
