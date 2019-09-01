#include<stdio.h>
#include<math.h>


int main()
{
	double x1,x2,x3,y1,y2,y3,A,B,C,k,g,f,H,K,Y1,Y2,X1,X2,r,c,d,e;
	
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
	{
		A = x1 * x1 + y1 * y1 ;	B = x2*x2 + y2*y2 ; C = x3*x3 + y3*y3 ;		
		X1 = x1-x2;		X2 = x2-x3;   Y1 = y1-y2;   Y2 = y2-y3;		
		g = ( Y2 *( B-A) - Y1*(C-B) ) / ( 2 * (X1*Y2 - X2*Y1) );
		f = (B - A - (2 * g * X1) ) / ( 2 * Y1);
		k = - A - 2 * g * x1 - 2 * f * y1;
		
		H = -g ;   K = -f ;  r = sqrt(g*g +f*f - k);
		if(H < 0)
			printf("(x + %.3lf)^2 + ",-1*H);
		else
			printf("(x - %.3lf)^2 + ",H);
		if(K < 0)
			printf("(y + %.3lf)^2 = ",-1*K);
		else
			printf("(y - %.3lf)^2 = ",K);
		printf("%.3lf^2\n",r);
		
		
		if(g < 0)
			printf("x^2 + y^2 - %.3lfx ",-2*g);
		else
			printf("x^2 + y^2 + %.3lfx ",2*g);
		if(f < 0 )
			printf("- %.3lfy ",-2*f);
		else
			printf("+ %.3lfy ",2*f);
		if(k < 0 )
			printf("- %.3lf = 0",-1*k);
		else
			printf("+ %.3lf = 0",k);
		printf("\n\n");
	}
	
	return 0;
}
