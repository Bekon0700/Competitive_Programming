#include<stdio.h>
#include<math.h>

int main()
{
	double  p=2*acos(0),S,V,Re,s,A,R,r,t,a,b,c;
	
	while( scanf("%lf%lf%lf",&a,&b,&c) == 3 )
	{
		s = a + b + c ;
		
		A = acos((b*b+c*c-a*a)/(2*b*c)) ;
		R = a /( 2 * sin(A) );
		t = b * c * sin(A)/2 ;
		s/=2;
		r = t / s;
		S = (p * R * R) - t ;
		Re = p * r * r;
		V = t - Re ;
		printf("%.4lf %.4lf %.4lf\n",S,V,Re);
	
	}

	return 0 ;
}
