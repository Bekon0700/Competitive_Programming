#include<stdio.h>
#include<math.h>


int main()
{
	double x[5],y[5],a[2],b[2],k[2];
	
	
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3])==8)
	{
		
		if(fabs(x[0]-x[2])<0.001 && fabs(y[0]-y[2])<0.001)
		{
			a[0] = x[0], b[0] = y[0];
			x[0] = x[1], y[0] = y[1];
			x[1] = a[0], y[1] = b[0];			
		}
		else if(fabs(x[0]-x[3])<0.001 && fabs(y[0]-y[3])<0.001)
		{
			a[0] = x[0], b[0] = y[0];
			x[0] = x[1], y[0] = y[1];
			x[1] = a[0], y[1] = b[0];
			
			a[0] = x[3], b[0] = y[3];
			x[3] = x[2], y[3] = y[2];
			x[2] = a[0], y[2] = b[0];
			
		}
		else if(fabs(x[1]-x[3])<0.001 && fabs(y[1]-y[3])<0.001)
		{
			a[0] = x[3], b[0] = y[3];
			x[3] = x[2], y[3] = y[2];
			x[2] = a[0], y[2] = b[0];
		}
			
		a[0] = y[0]-y[1];	
		b[0] = x[1]-x[0];
		k[0] = -a[0]*x[3] - b[0]*y[3];		
		
		a[1] = y[2]-y[3];	
		b[1] = x[3]-x[2];
		k[1] = -a[1]*x[0] - b[1]*y[0];		
		
		
		x[4] = (k[1]*b[0] - k[0]*b[1]) / (a[0]*b[1] - a[1]*b[0]);
		y[4] = (k[0]*a[1] - k[1]*a[0]) / (a[0]*b[1] - a[1]*b[0]);
		
		if(fabs(x[4])<0.001)
			printf("0.000 ");
		else
			printf("%.3lf ",x[4]);
		if(fabs(y[4])<0.001)
			printf("0.000\n");
		else
			printf("%.3lf\n",y[4]);
		
		
 	}

	return 0;
}
