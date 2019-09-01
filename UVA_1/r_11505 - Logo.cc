#include<stdio.h>
#include<math.h>
#define pi acos(0)/90

int main()
{
	int i,t,n;
	double x,y,d,T;
	char dir[10];
	
	scanf("%d",&t);
	while(t--)
	{
		x = y = T = 0 ;
		scanf("%d",&n);
		for(i=0; i < n ;i++)
		{
			scanf("%s%lf",dir,&d);
			if(dir[0] == 'r' )
				T -= d ;
			else if(dir[0] == 'l')			
				T += d ;
			else if(dir[0]=='f')
			{
				y += (d * sin( pi * T ) ) ;
				x += (d * cos( pi * T ) ) ;
			}
			else if(dir[0]=='b')
			{
				y -= (d * sin( pi * T ) ) ;
				x -= (d * cos( pi * T ) ) ;
			}
		}
		x = sqrt( x*x + y*y);
		printf("%.0lf\n",x);		
	}
	return 0 ;
}
