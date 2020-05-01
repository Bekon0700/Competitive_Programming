#include<stdio.h>
#include<math.h>

double a[109];

void CUBE();
int main()
{
	int i,p,q;
	double x,y,z,n;
	
	CUBE();
	
	while(scanf("%lf",&n)==1 && n)
	{
		p = pow(n,(1/3.0));
		/*if( a[p] == n )
		{
			x = p;
			printf("%.4lf\n",x);
			continue;
		}
		*/
		if(a[p+1] == n)
		{
			x = p+1;
			printf("%.4lf\n",x);
			continue;
		}	
		x = (n - a[p]) / ( 3 * p * p );
		x += p;
		printf("%.4lf\n",x);
	}
	
	return 0;
}

void CUBE()
{
	int m;
	a[0]=1;
	for(m=1;a[m-1]<1000010;m++)	
		a[m] = m*m*m;
	
}
