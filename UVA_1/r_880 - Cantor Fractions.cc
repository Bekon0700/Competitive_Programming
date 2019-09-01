#include<stdio.h>
#include<math.h>
#define er 1e-5

int main()
{
	long long a,x,y,n,d;
	
	while(scanf("%lld",&a) == 1)
	{
		n = (sqrt(8.0 *a + 1 )+ er - 1  ) / 2;
		d = a - (n*(n+1)) / 2 ;
		if(d)
		{
			x = n + 2 - d ;
			y = n + 2 - x ;
		}
		else
		{
			x = 1 ;
			y = n ;
		}		
		printf("%lld/%lld\n",x,y);
	}
	return 0;
}
