#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
	int n,i,j,t,k;
	double sides[100006],x,s,m;

	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf",&sides[i]);
		sort(&sides[0],&sides[n]);
		m = x = 0 ;

		for(i=n-1,k=0; i>1 && k< 10;i--)
			if( sides[i-2] + sides[i-1] > sides[i] )
			{
				s =(sides[i-2]+sides[i-1] + sides[i])/2;
				x = s * (s-sides[i-2])*(s-sides[i-1])*(s-sides[i]);
				k++;
				
				if(m<x)
					m=x;
			}
		m=sqrt(x);
		printf("%.2lf\n",m);

	}
	return 0 ;
}
