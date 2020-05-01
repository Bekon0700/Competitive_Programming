#include<stdio.h>
#include<math.h>


int main()
{
	double a,b,A,T,pi= 2*acos(0),x,L;
	int i=1;
	
	while(scanf("%lf : %lf",&a,&b)==2)
	{
		A = atan(a/b);
		T = pi - 2*A;
		x = 2 + T/sin(A) ;
		L = 400.0 / x ;
		printf("Case %d: %lf %lf\n",i++,L,L*b/a);
	}
	return 0;	
}
