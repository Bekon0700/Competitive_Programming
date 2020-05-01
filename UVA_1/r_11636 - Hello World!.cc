#include<stdio.h>
#include<math.h>


int main()
{
	int n,x,i=1;
	
	while(scanf("%d",&n)==1 && n > 0)	
	{
		x = ceil( log2(n) );
		
		printf("Case %d: %d\n",i++,x);
	}


	return 0;
}
