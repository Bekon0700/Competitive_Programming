#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,k,l,x,y;	
	char en[10000],de[10000],z='0';
	
	while(gets(en))
	{
		l=strlen(en);
		l -- ;
		
		if(en[0]>47 && en[0] < 59)
		{
			k = 0 ;
			
			while( l > -1)
			{
				if(en[l] != '1' )
				{
					x = ( en[l--] - z ) * 10 ;
					x += ( en[l--] - z )  ;
				}
				else
				{
					x=100;
					l -- ;
					x += ( ( en[l--] - z ) * 10 );
					x += ( en[l--] - z )  ;
				
				}
				de[k++] = x ;
			}
			de[k] = '\0';
			printf("%s\n",de);
		}
		else
		{
			while(l>-1)	
			{
				x = en[l--];
				while(x != 0)				
				{
					y = x % 10 ;
					x /= 10 ;
					printf("%d",y);  					
				}
			}
			printf("\n");
		}
	}

	return 0 ;
}
