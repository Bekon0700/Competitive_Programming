#include<stdio.h>
#include<string.h>

int main()
{
	int l=0,u=11,v;
	char c[20];
	
	while(scanf("%d",&v)==1 && v)
	{
		scanf(" %[^\n]",c);
		if( !strcmp(c,"right on") )
		{
			if(v < u && v > l)	
				printf("Stan may be honest\n");
			else
				printf("Stan is dishonest\n");
			u = 11 ; l = 0;
			
		}
		else if(!strcmp(c,"too high"))
		{
			if(v < u)			
				u = v ;
		}
		else if(!strcmp(c,"too low"))
		{
			if( v > l )
				l =  v ;
		}
		
	}
	return 0;
}
