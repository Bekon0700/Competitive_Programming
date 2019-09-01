#include<stdio.h>


int main()
{
	int i,x=0;
	char c;
	//freopen("in.txt","r",stdin);
	while(scanf("%c",&c)==1)
	{
		if(c>47 && c<58)	
		{
			x +=(c-48);	
		}
		else if(c=='\n' || c == '!')
			printf("\n");
		else if(c=='b')
		{
			for(i=0;i<x;i++)
			printf(" ");
			x =0;
		}
		else
		{
			for(i=0;i<x;i++)
				printf("%c",c);
			x=0;
		}
			
		
	}
	
	return 0;
}
