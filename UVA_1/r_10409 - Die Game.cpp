#include<stdio.h>

int main()
{
	int i,t,n,w,e,s,b,f,N;
	char a[6];
	
	while(scanf("%d",&N)==1 && N)
	{
		t = 1 ;
		w = 3 ;
		n = 2 ;
		for(i=0;i<N;i++)
		{
			scanf("%s",a);
			switch(a[0])	
			{
				case 'n':	f = t ;
							t = 7 - n ; 
							n = f ;
							break;
				
				case 'w':	f = t ;
							t = 7 - w ; 
							w = f ;
							break;

				case 's':	f = t ;
							t = n ; 
							n = 7 - f ;
							break;

				default:	f = t ;
							t = w ; 
							w = 7 - f ;
							break;
			}
		}
		printf("%d\n",t);
	}
	return 0; 
}
