#include<stdio.h>

int I[1000002];
double F[1000002];

int main()
{
	int i,j=0,n;
	double x=1;
	
	for(i=1;i<1000001;i++)
	{
		x *= 0.5;
       	if(1>x)
		{
			x*=10;
 			j++;
			
		}
		F[i]=x;	
		I[i]=j;
	}
	while(scanf("%d",&n)==1)
	{
		printf("2^-%d = %.3lfe-%d\n",n,F[n],I[n]);
		
	}

	return 0;
}
