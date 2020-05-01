#include<stdio.h>
#include<math.h>

int main()
{
	double a[2],b[2],c[2],ab,bc,ca,x,y,z,s;
	int n,i;

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&a[0],&a[1],&b[0],&b[1],&c[0],&c[1]);
		x = a[0] - b[0] ;
		y = a[1] - b[1] ;
		ab = sqrt(x*x + y*y) ;
		x = c[0] - b[0] ;
		y = c[1] - b[1] ;
		bc = sqrt(x*x + y*y) ;
		x = a[0] - c[0] ;
		y = a[1] - c[1] ;
		ca = sqrt(x*x + y*y) ;
		s = (ab+bc+ca)/2;
		y = s*(s-ab)*(s-bc)*(s-ca);
		x =sqrt(y);
		z = x / 7 ;
		
		x = ceil(z) ;
		y = floor(z) ;
		
		
		if( z-x > y-z )
			printf("%.0lf\n",x);
		else
			printf("%.0lf\n",y);
	
	}

	return 0 ;
}


