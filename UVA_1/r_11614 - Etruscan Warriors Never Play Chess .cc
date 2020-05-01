#include<stdio.h>
#include<math.h>
#define E 1e-5
int main()
{
	long long i,j,n,x,m;
	
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%lld",&x);	
		n = sqrt( 8*x + 1 + E) - 1;
		n >>= 1;
		
		printf("%lld\n",n);
	}

	return 0;
}
