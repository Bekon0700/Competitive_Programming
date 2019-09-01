#include<stdio.h>

int main()
{
	int  xll, yll, xur, yur, i, n, m, a, x1, x2, y1, y2, t;
	
	scanf("%d",&n);
	n++;

	for(t=1;t<n;t++)
	{
		xll = yll = xur = yur = 0;
		scanf("%d",&m);
			scanf("%d%d%d%d",&xll,&yll,&xur,&yur);	
		for(i=1;i<m;i++)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);	
			if(x1 > xll)	xll = x1;
			if(y1 > yll)	yll = y1;
			if(x2 < xur)	xur = x2;
			if(y2 < yur)	yur = y2;
		}
		
		if( xll < xur && yll < yur)
		{
			a = (xur - xll) * (yur - yll);
			printf("Case %d: %d\n",t, a );
		}
		else 
			printf("Case %d: %d\n",t,0);
	}
	return 0;
}
