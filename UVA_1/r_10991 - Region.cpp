#include<stdio.h>
#include<math.h>

int main()
{
	int t;
	double r1,r2,r3,s,c1,c2,c3,a,b,c,A,B,C,x,area ;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf",&r1,&r2,&r3);
		a = r1+r2;
		b = r2+r3;
		c = r3+r1;
		s = (a+b+c)/2;
		area = sqrt(s*(s-a)*(s-b)*(s-c));
		A = acos((b*b+c*c-a*a)/(2*b*c));
		B = acos((a*a+c*c-b*b)/(2*c*a));
		C = acos((a*a+b*b-c*c)/(2*a*b));
		c1 = r1 * r1 * B/2 ;
		c2 = r2 * r2 * C / 2 ;
		c3 = r3*r3 * A / 2;
		x = area - c1 - c2 - c3 ;
		printf("%.6lf\n",x);
 	
	}

	return 0;
}
