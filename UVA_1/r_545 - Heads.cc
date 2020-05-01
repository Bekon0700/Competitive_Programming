#include<stdio.h>
#define ee 1e-8

int I[9002];
double F[9002];

int main()
{
	int i,j=0,n,t;
	double x=1;
	
	for(i=1;i<9002;i++)
	{
		x *= 0.5;
       	if(1>x)
		{
			x*=10.0;
 			j++;
			
		}
		F[i]=x;	
		I[i]=j;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		
		printf("2^-%d = %.3lfE-%d\n",n,F[n]+ee,I[n]);
		
	}

	return 0;
}
