#include<stdio.h>
#include<math.h>

int main()
{
	int N,M,i,a;
	double A,x,y;
	while(scanf("%d%d",&N,&a) == 2 && N)
	{
		M = 0 ;
		for(i=0;i<N;i++)
		{
			scanf("%lf%lf",&x,&y);		
			if( sqrt( pow((x-0), 2) + pow((y-0), 2) ) > a || sqrt( pow((x-0), 2) + pow((y-a), 2) ) > a || sqrt( pow((x-a), 2) + pow((y-0), 2) ) > a || sqrt( pow((x-a), 2) + pow((y-a), 2) ) > a  )
				;
			else	M++;
		}
		A = M * a * a ; 
		A /= N ;
		printf("%.5lf\n",A);
	}
	return 0;
}
