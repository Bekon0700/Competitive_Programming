#include<stdio.h>

int main()
{
	int l=0,u=11,v;
	char c2[10],c1[10];
	
	while(scanf("%d",&v)==1 && v)
	{
		scanf("%s %s",c1,c2);
		if( c2[0]== 'o' )
		{
			if(v < u && v > l)	
				printf("Stan may be honest\n");
			else
				printf("Stan is dishonest\n");
			u = 11 ; l = 0;
			
		}
		else if(c2[0]== 'h')
		{
			if(v < u)			
				u = v ;
		}
		else if(c2[0]== 'l')
		{
			if( v > l )
				l =  v ;
		}
		
	}
	return 0;
}
