#include<stdio.h>
#include<math.h>

int main()
{
	long long a,x,y,n,m,d,t=0;
	double q;
	
	
	while(scanf("%lld",&a) == 1)
	{
		n = (sqrt(8*a+1)+ 1e-5 - 1  ) / 2;
		d = a - (n*(n+1)) / 2 ;
		if(n&1)
		{
			if(d)
			{
				y = n + 2 - d ;
				x = n + 2 - y ;
				
			}
			else
			{
				x = 1 ;
				y = n ;
			}			
			
		}
		else
		{
			if(d)
			{
				x = n + 2 - d;
				y = n + 2 -x;
			}
			else			
			{
				x = n ;	
				y = 1 ;
			}
			
		}
		printf("TERM %lld IS %lld/%lld\n",a,x,y);
	}
	return 0;
}
