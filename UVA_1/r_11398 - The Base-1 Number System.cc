#include<stdio.h>

int main()
{
	int i,j,x=0,f=0;
	char a[110];
	
	while(scanf("%s",a)==1 && a[0] != '~')
	{
		if(a[0] == '#')
		{
			printf("%d\n",x);	
			x=0;
		}
		j=0;
		while(a[j] == '0')
			j++;	
				
		if(j==1)
			f = 1 ;
		else if(j==2)
			f = 0; 
			else if(j>2)
			{
				j -=2;
				while(j--)	
				{
					x <<=1;
					x += f ;						
				}
			}
	}
	return 0;
}
