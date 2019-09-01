#include	<stdio.h>
#include	<math.h>

#define		PI		2*acos(0)
#define		ER		1e-10

int main()
{
	int t=1,n;
	double u,v,x,d,tp,tt;
	
	scanf("%d",&n);
	n++;
	for(t=1;t<n;t++)
	{
		scanf("%lf%lf%lf",&d,&v,&u);
		if( u > v && u > 0 && v > 0)	
		{
			tt = d/u;
			x = acos( - v / u );
			
			x -=(PI/2);
			tp = d/(u*cos(x));
			x = tp - tt;
			printf("Case %d: %.3lf\n",t,x);
		}
		else
			printf("Case %d: can't determine\n",t);
		
	}

	return 0;
}
