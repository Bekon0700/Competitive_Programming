#include<stdio.h>
#include<math.h>

double a[1001],x,avg,d1,d2,ad,y;

int main()
{
	int i,n;
	
	while(scanf("%d",&n)==1 && n)
	{
		ad = 0;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&a[i]);
			ad += a[i];
		}
		avg = floor((ad/n)*100.0+0.5)/100.0;
		x = y = 0 ;
		for(i=0;i<n;i++)
			if(a[i]>avg)
				x += a[i] - avg; 
			else
				y += avg - a[i];
		if(x<y)	
			avg = floor(x*100.0+0.5)/100.0;		
		else
			avg = floor(y*100.0+0.5)/100.0;		
		printf("$%.2lf\n",avg);
	}

	return 0;
}
