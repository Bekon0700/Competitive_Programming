#include<stdio.h>
#include<math.h>

int main()
{
	int  c, x, y, n ;
	
	while(scanf("%d",&n)==1)
	{
		y = 0 ;
		c = x= 1 ;
		while(c != 0 )
		{
			c = x % n ;
			y ++;
			x = c*10 ;
			x ++ ;
		}
		printf("%d\n",y);
	}

	return 0 ; 
}
